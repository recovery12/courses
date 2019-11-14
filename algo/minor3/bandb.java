class minor3
{
public static void main(String[] args){
   int[] buildings = {2,1};
   System.out.println(calcMoves(buildings));
}

  public static int calcMoves(int[] buildings){
      
    int j = buildings.length -1;
    int i = 0;
    
    int moves = 0;
    while(i < j){
    
      int iI = i;
      int jI = j;
      
      while(i+1 <= j && buildings[i] <= buildings[i+1]){
          buildings[i] = 0;
          i++;
      }
      System.out.println(buildings);
      if(i > iI)
        moves++;
      
      while(j-1 >= i && buildings[j] <= buildings[j-1]){
          buildings[j] = 0;
          j--;
      }
      System.out.println(buildings);
      if(j < jI)
        moves++;
      
      i++;
      j--;
    }
    System.out.println(moves);
    return moves;
  }
}
