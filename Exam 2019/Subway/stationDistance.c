#include <stdlib.h>
#include "stationDistance.h" 
int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,int G_destination,int startStation[],int endStation[]){
    int distance = 0;
    if(startStation[0] == endStation[0]){
        if(startStation[0] == 0){
            if(startStation[1] < endStation[1]){
                while(startStation[1] < endStation[1]){
                    distance += R_distance[startStation[1]-1];
                    startStation[1]++;
                }
            }
            else{
                while(startStation[1] > endStation[1]){
                    distance += R_distance[startStation[1]-2];
                    startStation[1]--;
                }
            }
        }
        else if(startStation[0] == 1){
            if(startStation[1] < endStation[1]){
                while(startStation[1] < endStation[1]){
                    distance += G_distance[startStation[1]-1];
                    startStation[1]++;
                }
            }
            else{
                while(startStation[1] > endStation[1]){
                    distance += G_distance[startStation[1]-2];
                    startStation[1]--;
                }
            }
        }
        else{
            if(startStation[1] < endStation[1]){
                while(startStation[1] < endStation[1]){
                    distance += B_distance[startStation[1]-1];
                    startStation[1]++;
                }
            }
            else{
                while(startStation[1] > endStation[1]){
                    distance += B_distance[startStation[1]-2];
                    startStation[1]--;
                }
            }
        }
    }
    else{
        if(startStation[0] == 0){
            if(startStation[1] > G_origin){
                while(startStation[1] > G_origin){
                    distance += R_distance[startStation[1]-2];
                    startStation[1]--;
                }    
            }
            else{
                while(startStation[1] < G_origin){
                    distance += R_distance[startStation[1]-1];
                    startStation[1]++;
                }    
            }
            int idx = 1;
            if(endStation[0] == 1){
                while(idx < endStation[1]){
                    distance += G_distance[idx-1];
                    idx++;
                }
            }
            else if(endStation[0] == 2){
                while(G_distance[idx-1] != 0){
                    distance += G_distance[idx-1];
                    idx++;
                }
                idx = G_destination;
                if(endStation[1] > G_destination){
                    while(idx < endStation[1]){
                        distance += B_distance[idx-1];
                        idx++;
                    }
                }
                else{
                    while(idx > endStation[1]){
                        distance += B_distance[idx-2];
                        idx++;
                    }
                }
            }
        }
        else if(startStation[0] == 1){
            if(endStation[0] == 0){
                while(startStation[1] > 1){
                    distance += G_distance[startStation[1]-2];
                    startStation[1]--;
                }
                int idx = G_origin;
                if(G_origin > endStation[1]){
                    while(idx > endStation[1]){
                        distance += R_distance[idx-2];
                        idx--;
                    }
                }
                else{
                    while(idx < endStation[1]){
                        distance += R_distance[idx-1];
                        idx++;
                    }
                }
            }
            else{
                int idx = startStation[1];
                while(G_distance[idx-1] != 0){
                    distance += G_distance[idx-1];
                    idx++;
                }
                idx = G_destination;
                if(idx > endStation[1]){
                    while(idx > endStation[1]){
                        distance += B_distance[idx-2];
                        idx--;
                    }
                }
                else{
                    while(idx < endStation[1]){
                        distance += B_distance[idx-1];
                        idx++;
                    }
                }
            }
        }
        else{
            if(startStation[1] > G_destination){
                while(startStation[1] > G_destination){
                    distance += B_distance[startStation[1]-2];
                    startStation[1]--;
                }    
            }
            else{
                while(startStation[1] < G_destination){
                    distance += B_distance[startStation[1]-1];
                    startStation[1]++;
                }    
            }
            int idx, meow = 0;
            while(G_distance[meow] != 0)
                meow++;
            idx = meow+1;
            if(endStation[0] == 1){
                while(idx > endStation[1]){
                    distance += G_distance[idx-2];
                    idx--;
                }
            }
            else{
                while(idx-1 > 0){
                    distance += G_distance[idx-2];
                    idx--;
                }
                idx = G_origin;
                if(endStation[1] > idx){
                    while(idx < endStation[1]){
                        distance += R_distance[idx-1];
                        idx++;
                    }
                }
                else{
                    while(idx > endStation[1]){
                        distance += R_distance[idx-2];
                        idx--;
                    }
                }
            }
        }
    }
    return distance;
}

