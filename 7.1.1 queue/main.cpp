#include<iostream>
#include<thread>
#include<chrono>
#include<atomic>
#include<Windows.h>


using namespace std::chrono_literals;

void add_client(std::atomic<int>& queue, std::atomic<int>& total_clients)
{
	while (total_clients < 15)
	{
		++queue;
		++total_clients;
		std::this_thread::sleep_for(500ms);
	}
}

void remove_client(std::atomic<int>& queue, std::atomic<int>& total_clients)
{
	while (queue > 0)
	{
		system("cls");
		--queue;
		std::cout << "Человек в очереди: " << queue;
		std::this_thread::sleep_for(1s);
	}
}





int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::atomic<int> queue = 5;
	std::atomic<int> total_clients = 5;

	std::thread th1(add_client,std::ref(queue),std::ref(total_clients));
	std::thread th2(remove_client, std::ref(queue), std::ref(total_clients));

	th1.join();
	th2.join();

	return 0;
}