bool checkPowersOfThree(int n) 
{
   int target = n;
   while(target > 0)
   {
        if(target % 3 == 2)
        {
            return false;
        }
        target /= 3;
   }
   return true;
        
}
