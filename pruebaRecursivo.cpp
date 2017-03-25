/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: Zero one knapsack recursive
 */
 
#include<stdio.h>
 
#define N 128
 
int CostTable[N][N];
int Weight[N];
int Benefit[N];
 
int total_weight = 11;
int item_count = 5;
 
inline int max(int a, int b){
    return a > b ? a : b;
}
 
int RecursiveKnapsack(int i, int w){
  printf("platos: %d umbral %d\n", i, w);
  if(i == 0 || w == 0)
        return 0;
 
    if(Weight[i] > w)
        CostTable[i][w] = RecursiveKnapsack(i - 1, w);
    else
        CostTable[i][w] = max(RecursiveKnapsack(i - 1, w), RecursiveKnapsack(i - 1, w - Weight[i]) + Benefit[i]);

  return CostTable[i][w];
}
 
int main(){
 
    Weight[1] = 5;
    Weight[2] = 1;
    Weight[3] = 7;
    Weight[4] = 2;
    Weight[5] = 6;
 
    Benefit[1] = 180;
    Benefit[2] = 10;
    Benefit[3] = 280;
    Benefit[4] = 60;
    Benefit[5] = 220;
 
    /*
     * Set all values of 2D matrix CostTable to Minus 1
     */
    for(int i = 0; i <= item_count; ++i)
        for(int w = 0; w <= total_weight; ++w)
            CostTable[i][w] = -1;
	
    printf("Max Benefit: %d\n", RecursiveKnapsack(item_count, total_weight));
 
    for(int i = 0; i <= item_count; ++i) {
      printf("\n");
        for(int w = 0; w <= total_weight; ++w)
            printf("%d ", CostTable[i][w]);
    }
    return 0;
}