#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

int findMinVertex(int* distance, bool* isVisited, int vertices){
    int minVertex = -1; // initially no vertex is minimum

    //we gotta scan the whole array and find the minimum distance vertex (or return it)
    //u just gotta find minimum element from array 
    for (int i = 0; i < vertices; i++){
        if(!isVisited[i] &&  (minVertex == -1 || distance[i] <distance[minVertex]))
            minVertex = i;
    }
    return minVertex;    
}

void dijkstra(int** edges, int vertices){
    int* distance = (int*) malloc(sizeof(int));
    bool* isVisited = (bool *) malloc(sizeof(bool));

    //initially distance is ∞ and for that m using int_max and isVisited should be false initially coz we haven't visited yet.
    for (int i = 0; i < vertices; i++){
        distance[i] = INT_MAX;
        isVisited[i] = false;
    }
    distance[0] = 0; //source distance set to zero from ∞

// ------------------------------------------------------------------------------------------------------------------------------

    //now u gotta pick min. element one by one from all vertex and explore them 

    for (int i = 0; i < vertices - 1; i++) //suppose u reached last vertex.. so u won't be checking it's neighbours since all neighbours at that time would have been visited .. so u can exclude that vertex from loop that's y vertex-1
    {
        int minVertex = findMinVertex(distance,isVisited,vertices); //so we gotta get minVertex which is minimum from source vertex
        // now we got minVertex so mark is as true
        isVisited[minVertex] = true;

        //now explore every vertex.. since we'r having adjancency matrix that's why we gotta go till vertices

        for (int j = 0; j < vertices; j++){
            if(edges[minVertex][j]!=0 && !isVisited[j]){
            //edges[minVertex][j] means there exist a edge b/w minVertex and j .. if it's not equal to -1 then only there's a edge
            //!isVisited[j] means that neighbour should not have been visited

            int dist = distance[minVertex] + edges[minVertex][j];
            //now if the dist is less than distance then update it.. 
            if(dist < distance[j])
                distance[j] = dist;
            }            
        }
    }

    for (int i = 0; i < vertices; i++){
        printf("%d  %d\n",i,distance[i]);
    }
    
    free(isVisited);
    free(distance);    
}

int main(){    
    int arr[5][5] = {   {0,1,1,1,0},
                        {1,0,0,1,1},
                        {1,0,0,1,0},
                        {1,1,1,0,1},
                        {0,1,0,1,0}};

    dijkstra()  //src = 0 means start from 0th node

    return 0;
}
