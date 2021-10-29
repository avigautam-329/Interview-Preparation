#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       // wE DON'T NEED TO USE THE CONCEPT OF STACK OR QUEUES IN THIS QUESTION.
       // We will be taking a very different approach.
       
       // If we start from the index 0 and it is not able to go froward at some point x, then out next starting point will
       // be x + 1.
        
        // We will amintain 2 values, requiredFuel and extraFuel.
        // The required fuel will always containthe fuel which is needed even after filling up the tank
        // And also using the extra fuel.
        // The extra fuel is the fuel remaining after traversing the distance from one to another petrol pump.
        
        int requiredFuel = 0;
        int extraFuel = 0;
        
        
        int currentStarting = 0;
        
        for(int i = 0; i < n; i++){
            if(p[i].petrol + extraFuel >= p[i].distance){
                extraFuel = p[i].petrol + extraFuel - p[i].distance;
            }else{
                requiredFuel += p[i].distance - (p[i].petrol + extraFuel);
                extraFuel = 0;
                currentStarting = i + 1;
            }
        }
        
        if(extraFuel > requiredFuel){
            return currentStarting;
        }
        
        return -1;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends
