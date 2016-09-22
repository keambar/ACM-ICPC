/*
	problem judge
*/
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <utility>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<double , double > position;

const double PI = acos( -1.0 );
const int RI = 6378137;

//时间转换成秒
int dateToSecond( string date )
{
    char s[30];
    strcpy( s, date.c_str() );
    int HH, mm, ss;
    sscanf( s, "%d:%d:%d", &HH, &mm, &ss );
    int rst = ( HH - 10 ) * 60 * 60 + mm * 60 + ss;
    return rst;
}

//计算两点距离，算出用时。参数为两点经纬。
int usedtime( position a, position b )
{
    double dlat = ( a.second - b.second ) * 1. / 2, dlng = ( a.first - b.first ) * 1. / 2;
    double dis = 2 * RI * asin( sqrt( sin( PI / 180 * dlat ) * sin( PI / 180 * dlat ) +
                                      cos( PI / 180 * a.second ) * cos( PI / 180 * b.second )
                                      * sin( PI / 180 * dlng ) * sin( PI / 180 * dlng )
                                    )
                              );

    return int( dis / 3 );
}

//计算罚款。参数为实际送达时间，和承诺送达时间。
int finecost( int reachtime, int promisedtime )
{
    if ( reachtime <= promisedtime ) return 0;
    //超时秒数化为分，并向上取整
    int dt = ( reachtime - promisedtime + 59 ) / 60;

    //超时代价太高
    if ( dt >= 20 ) return -1;
    return ( int ) pow( 2.0, dt );
}
//餐厅数据
struct rst {
    int rst_id;
    position pos_rst;
    int make_order_time;
    rst() {}
    rst( int rst_id, double lng, double lat, int make_order_time ): rst_id( rst_id ), make_order_time( make_order_time )
    {
        pos_rst = make_pair( lng, lat );
    };
};
//订单数据
struct order {
    int order_id, rst_id;
    position pos_cus;
    int promised_at;
    int makeup_at;
    int created_at;
    order() {}
    order( int order_id, int rst_id, double lng, double lat, string created, string promised ): order_id( order_id ), rst_id( rst_id )
    {
        pos_cus = make_pair( lng, lat );
        promised_at = dateToSecond( promised );
        created_at = dateToSecond( created );

    };
};

//骑手数据
struct courier {
    int courier_id;
    position pos_courier;
    int max_load;
    courier() {}
    courier( int courier_id, double lng, double lat, int max_load ): courier_id( courier_id ), max_load( max_load )
    {
        pos_courier = make_pair( lng, lat );
    }
};

unordered_map<int, rst >  in_rst;
unordered_map<int, order >  in_order;
unordered_map<int, courier > in_courier;

int n, m, k;

map<int, int> orderfinish; //记录订单完成时间，
map<int, int> usedcourier; //记录骑手使用情况

//读入输入数据
void readinput()
{
    freopen( "testinput.txt", "r", stdin );
    scanf( "%d %d %d\n", &n, &m, &k );
    char s[100];
    for( int i = 0; i < n; ++i ) {
        gets( s );
        int id, usedtime;
        double lng, lat;
        sscanf( s, "[%d,%lf,%lf,%d]", &id, &lng, &lat, &usedtime );
        //printf("[%d,%lf,%lf,%d]",id,lng,lat,usedtime);
        rst tmp = rst( id, lng, lat, usedtime );
        in_rst.insert( make_pair( id, tmp ) );
    }

    for( int i = 0; i < m; ++i ) {
        gets( s );
        int order_id, rst_id;
        double lng, lat;
        char promisedtime[20], createdtime[20];
        sscanf( s, "[%d,%d,%lf,%lf,%*s %[0-9|:],%*s %[0-9|:]]", &order_id, &rst_id, &lng, &lat, promisedtime, createdtime );
        //printf("[%d,%d,%lf,%lf,%s,%s]",order_id,rst_id,lng,lat,promisedtime,createdtime);
        order tmp = order( order_id, rst_id, lng, lat, createdtime, promisedtime );
        tmp.makeup_at = tmp.created_at + in_rst[rst_id].make_order_time;
        in_order.insert( make_pair( order_id, tmp ) );
    }

    for( int i = 0; i < k; ++i ) {
        gets( s );
        int courier_id, max_load;
        double lng, lat;
        sscanf( s, "[%d,%lf,%lf,%d]", &courier_id, &lng, &lat, &max_load );
        //printf("[%d,%lf,%lf,%d]",courier_id,lng,lat,max_load);
        courier tmp = courier( courier_id, lng, lat, max_load );
        in_courier.insert( make_pair( courier_id, tmp ) );
    }
}

/*
对于合法的操作序列，输出cost
非法的操作序列，输出-1
超时过长导致cost过大（超过100w），输出-2
非法判断条件：
1.全程骑手速度不超过3m/s。
2.取餐时间晚于出餐时间。
3.一个订单只被同一个骑手取送一次。
4.骑手超过负载。
5.所有订单都完成。
6.同一个骑手的操作序列满足时间不后退。
*/
int check()
{
    freopen( "output", "r", stdin );
    char s[100];
    //cnt记录使用过的骑手，pick记录骑手负载。
    int cnt = 0, pick = 0;
    while( gets( s ) > 0 ) {
        char time[30];
        int courier_id, num, order_id, type;

        //记录同一个骑手上一个操作和当前操作的位置和时间
        int id;
        int lasttime = 0, now;
        position lastpos, nowpos;

        double lng, lat;
        sscanf( s, "%d,%d,%lf,%lf,%d,%d,%*s %s", &courier_id, &num, &lng, &lat, &order_id, &type, time );
        now = dateToSecond( time );
        nowpos = make_pair( lng, lat );
        if( usedcourier.find( courier_id ) == usedcourier.end() ) {
            id = courier_id;
            usedcourier[courier_id] = 1;
            ++cnt;
            lasttime = now;
            lastpos = make_pair( lng, lat );
            //读入新骑手记录时，上个骑手的负载不为0，
            if( pick > 0 ) {
                return 0;
            }
        } else {
            //不是同一个骑手
            if( courier_id != id ) return -1;
            //同一骑手时间序列递减
            if( now < lasttime ) return -1;
            //3m/s的速度不满足经纬移动
            if( lasttime + usedtime( lastpos, nowpos ) > now ) return -1;

            //取餐操作
            if( type == 1 ) {
                //当前订单是否第一次被取餐
                if( orderfinish.find( order_id ) == orderfinish.end() ) {
                    ++pick;
                    //骑手超过负载。
                    if( pick > in_courier[courier_id].max_load ) {
                        return -1;
                    }
                    //取餐标记
                    orderfinish[order_id] = 0;
                    //取餐时间是早于出餐时间
                    if( now < in_order[order_id].makeup_at ) {
                        return -1;
                    }
                } else {
                    return -1;
                }
            }

            //送餐操作
            if( type == 0 ) {
                //送达的是被取过的订单
                if( orderfinish[order_id] == 0 ) {
                    //记录送达时间
                    orderfinish[order_id] = now;

                } else {
                    return -1;
                }
            }
        }

    }
    //完成的订单数量小于总订单量
    if( orderfinish.size() < k ) {
        return -1;
    }
    int cost = cnt * 200;
    unordered_map<int, order >::iterator it;
    for( int i = 0; i < k; ++i ) {
        for( it = in_order.begin(); it != in_order.end(); ++it ) {
            int order_id = (*it).second.order_id;
            int tmp = finecost( orderfinish[order_id], in_order[order_id].promised_at );
            if( tmp == -1 ) return -2;
            cost += tmp;
        }
    }
    return cost;
}
/*
	test
*/
int main()
{

    //readinput();
    //cout<<check();
    //cout << "tested" << endl;
    return 0;
}
