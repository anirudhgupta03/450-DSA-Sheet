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
       int start = 0;
       
       int excess = 0, deficit = 0;
       
       for(int i = 0; i < n; i++){
           
           if(p[i].petrol + excess >= p[i].distance){
               excess = p[i].petrol + excess - p[i].distance;
           }
           else{
               deficit += p[i].petrol + excess - p[i].distance;
               excess = 0;
               start = (i + 1)%n;
           }
       }
       //cout << excess << " " << deficit << endl;
       if(excess + deficit >= 0){
           return start;
       }
       return -1;
    }
};
