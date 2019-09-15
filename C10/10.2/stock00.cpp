#include <iostream>
#include "stock00.h"

//管理对某个公司股票的首次购买
void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if(n < 0)
    {
        std::cout << "Number of shares can't be negtive; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = 0;
    }
    share_val = pr;
    set_tot();
}

//增加持有股票
void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

//减少持有股票
void Stock::sell(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares sold can't be negative. Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        std::cout << "You can't sell more than you have! Transaction is abored.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    std::cout << "Company: " << company << std::endl;
    std::cout << "Shares: " << shares << std::endl;
    std::cout << "Share Price: $" << share_val;
    std::cout << "Total Worth: $" << total_val << std::endl;
}