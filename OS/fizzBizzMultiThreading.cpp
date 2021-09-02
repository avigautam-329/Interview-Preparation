#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

// We need to initialize mutex.
std::mutex mtx;

int currNum = 1;
int n = 100;

// Now we will create our four functions as:
void fizz(){
	
	mtx.lock();
	if(currNum > 100){
		return;
	}
	
	// Now we are in the critical section.
	if(currNum % 3 == 0 && currNum % 5 != 0){
		cout << "fizz" << endl;
		currNum++;
	}
	
	mtx.unlock();
}

void bizz(){
	
	mtx.lock();
	if(currNum > 100){
		return;
	}
	
	
	// Now we are in the critical section.
	if(currNum % 3 != 0 && currNum % 5 == 0){
		cout << "bizz" << endl;
		currNum++;
	}
	
	mtx.unlock();
}
void fizzbizz(){
	
	mtx.lock();
	if(currNum > 100){
		return;
	}
	
	
	
	// Now we are in the critical section.
	if(currNum % 3 == 0 && currNum % 5 == 0){
		cout << "fizzbizz" << endl;
		currNum++;
	}
	
	mtx.unlock();
}
void num(){
	
	mtx.lock();
	if(currNum > 100){
		return;
	}
	
	// Now we are in the critical section.
	if(currNum % 3 != 0 && currNum % 5 != 0){
		cout << currNum << endl;
		currNum++;
	}
	
	mtx.unlock();
}

int main(){
	
	// This is where we will create the threads for our process.
	for(int i = 0; i < 100 ; i++){
		std::thread t1(fizz);
		std::thread t2(bizz);
		std::thread t3(fizzbizz);
		std::thread t4(num);
	
		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}

	
	return 0;
}
