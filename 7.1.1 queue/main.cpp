#include<iostream>
#include<thread>
#include<chrono>
#include<Windows.h>


using namespace std::chrono_literals;

void add_client(int* queue, int* total_clients)
{
	while (*total_clients < 25)
	{
		++(*queue);
		++(*total_clients);
		std::this_thread::sleep_for(500ms);
	}
}

void remove_client(int* queue)
{
	while (*queue > 0)
	{
		system("cls");
		--(*queue);
		std::cout << "Человек в очереди: " << *queue;
		std::this_thread::sleep_for(1s);
	}
}





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int queue = 5;
	int total_clients = 5;
	std::thread th1(add_client, &queue, &total_clients);
	std::thread th2(remove_client, &queue);

	th1.join();
	th2.join();

	return 0;
}