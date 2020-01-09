#ifndef _DJS_MISC_H_
#define _DJS_MISC_H_

/* 
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or 
    (at your option) any later version. 
 
    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty of 
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
    GNU General Public License for more details. 
 
    You should have received a copy of the GNU General Public License 
    along with this program.  If not, see <http://www.gnu.org/licenses/> 
*/

#include"LinkedList.h"
#include"degeneracy_helper.h"
#include"degeneracy_algorithm_cliques_A.h"
#include"degeneracy_algorithm_cliques_V.h"
#include"degeneracy_algorithm_cliques_E.h"

#define max(x,y) (x > y? x:y)
#define min(x,y) (x < y? x:y)
#define MAX_CSIZE 400

void populate_nCr();

int nodeComparator(int node1, int node2);

void printArray(int* array, int size);

void printArrayOfLinkedLists(LinkedList** listOfLists, int size);

void printInt(int integer);

void destroyCliqueResults(LinkedList* cliques);

LinkedList** readInGraphAdjList(int* n, int* m);

LinkedList** readInGraphAdjListToDoubleEdges(int* n, int* m, char *fpath);


void runAndPrintStatsCliques_new(LinkedList** adjListLinked,
                               int n, const char * gname, 
                               char T, int max_k, int flag_d, double* cliqueCounts);

void runAndPrintStatsCliques(LinkedList** adjListLinked,
                               int n, const char * gname, 
                               char T, int max_k, int flag_d);


int findNbrCSC(int u, int v, int *CSCindex, int *CSCedges);

void moveFromRToXDegeneracyCliques( int vertex, 
                                    int* vertexSets, int* vertexLookup, 
                                    int* pBeginX, int* pBeginP, int* pBeginR);

void moveToRDegeneracyCliques( int vertex, 
                               int* vertexSets, int* vertexLookup, 
                               int** neighborsInP, int* numNeighbors,
                               int* pBeginX, int *pBeginP, int *pBeginR, 
                               int* pNewBeginX, int* pNewBeginP, int *pNewBeginR);

void fillInPandXForRecursiveCallDegeneracyCliques( int vertex, int orderNumber,
                                                   int* vertexSets, int* vertexLookup, 
                                                   NeighborListArray** orderingArray,
                                                   int** neighborsInP, int* numNeighbors,
                                                   int* pBeginX, int *pBeginP, int *pBeginR, 
                                                   int* pNewBeginX, int* pNewBeginP, int *pNewBeginR);

int findBestPivotNonNeighborsDegeneracyCliques( int** pivotNonNeighbors, int* numNonNeighbors,
                                                int* vertexSets, int* vertexLookup,
                                                int** neighborsInP, int* numNeighbors,
                                                int beginX, int beginP, int beginR);

void main_wrapper(char *file_path, char type, int max_clique_size, int data_flag, double* cliqueCounts);

#endif

