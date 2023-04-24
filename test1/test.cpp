#include "time.h"

int main(){
    //https://blog.csdn.net/weixin_43956732/article/details/109765323
    time_t begin = time(NULL);//time_t is a long long type var
    struct tm f = *localtime(&begin);
    std::cout<<begin<<std::endl;
    std::cout<< f.tm_hour <<std::endl;

    // 这是最基础的s，而ms呢？
    // to do with chrono library
    // https://blog.csdn.net/u012294613/article/details/124607286
    using namespace std::chrono;
    std::chrono::seconds five_seconds = std::chrono::seconds(5);//duration 5s
    auto five = duration<double,std::ratio<5,100000>>(1);

    std::cout<<five.count()<<"\n";

    auto one = 1s;
    std::this_thread::sleep_for(five);

    auto day = 24h;
    auto sec = seconds(day);
    std::cout<<sec.count()<<std::endl;
    day = duration_cast<hours>(sec);//强制转换了

    auto nowsec = system_clock::now();
    std::cout<<duration_cast<hours>(nowsec.time_since_epoch()).count()<<"\n";


    auto old = steady_clock::now();
    std::this_thread::sleep_for(one);
    auto now = steady_clock::now();
    auto duration = now - old;
    std::cout<< duration.count()<<" \n";

    return 0;
}