import java.io.*;
import java.util.*;

public class Main
{
	static Scanner sc = new Scanner(new BufferedInputStream(System.in));
	public static void main(String[] args)
	{
		int t = sc.nextInt();
		for(int i=0;i<t;i++)
			solveCase();
	}
	static void solveCase()
	{
		n = sc.nextInt(); m = sc.nextInt();
		init = new int[m];
		for(int i=0;i<m;i++)
			init[i] = sc.nextInt()-1;
		
		earliest = new boolean[m];
		for(int i=0;i<m;i++)
		{
			int lessCount = 0;
			for(int j=0;j<i;j++)
				if(init[j]<init[i])
					lessCount++;
			earliest[i] = lessCount==init[i];
		}
		
		memo = new long[n][n+1];
		for(long[] arr:memo)
			Arrays.fill(arr, -1L);
		System.out.println(solve(0, 0));
	}
	static int m, n;
	static long[][] memo;
	static int[] init;
	static boolean[] earliest;
	static long solve(int index, int start)
	{
		if(index>=n)
			return 1;
		if(memo[index][start]==-1)
		{
			long res = 0;
			for(int i=start;i<n;i++)
				if(index>=m || init[index]==i)
					res += solve(index+1, i+1);
			if(start>index)
				if(index>=m || earliest[index])
					res += solve(index+1, start);
			memo[index][start] = res;
		}
		return memo[index][start];
	}
}
