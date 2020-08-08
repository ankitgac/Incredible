#include<iostream>
#include<mutex>
#include<thread>
 
int count = 0,n=100;
 
std::mutex m;
 
void printEvenNum()
{
	while(count < n)
	{
		m.lock();

		if(count % 2 == 0)
		{
			std::cout <<" Even number thread:" << count << std::endl;
			count++;
		}
		if(count >= n)
		{
			m.unlock();
			return;
		}

		m.unlock();
	}
}
 
void printOddNum()
{
	while(count < n)
	{
		m.lock();

		if(count % 2 != 0)
		{
			std::cout<<" Odd Number thread:" << count <<std::endl;
			count++;
		}
		if(count >= n)
		{
			m.unlock();
			return;
		}

		m.unlock();
	}
}
 
int main()
{
   std::thread t1(printEvenNum);
   std::thread t2(printOddNum);
   t1.join();
   t2.join();
   return 0;
}
