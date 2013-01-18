import java.util.Scanner;
import java.util.HashSet;
import java.util.Collections;
import java.util.ArrayList;

class Solution
{
  public static void main(String args[])
  {
    Scanner in = new Scanner(System.in);
    HashSet<String> set = new HashSet<String>();

    String s;
    int n=in.nextInt(),l;

    for(int i=0;i<n;++i)
    {
      s=in.next();
      l=s.length();
      for(int j=0;j<l;++j)
        for(int k=j;k<l;++k)
	  set.add(s.substring(j,k+1));
    }
    
    ArrayList<String> arr=new ArrayList<String>(set);
    Collections.sort(arr);
    int len=arr.size();
    int q=in.nextInt(),k;
    for(int i=0;i<q;++i)
    {
      k=in.nextInt();
      if(k>len) System.out.print("INVALID\n");
      else System.out.print(arr.get(k-1)+"\n");
    }
  }
}
