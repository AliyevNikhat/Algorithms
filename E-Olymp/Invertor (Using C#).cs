using System;
using System.Collections;
using System.Collections.Generic;

namespace Problem
{
	class Program
	{
		static void Main()
		{
			int n = int.Parse(Console.ReadLine());
			int[] arr = new int[n]; 
			
			string input = Console.ReadLine(); 
			string[] inputs = input.Split(' '); 
			
			for (int i = 0; i < n; i++)
			{
				arr[i] = int.Parse(inputs[i]); 
			}
			
			int m=0, j = n - 1;
			while(m < j)
			{
				int temp = arr[m];
				arr[m] = arr[j];
				arr[j] = temp;
				m++;
				j--;
			}
			Console.WriteLine(string.Join(' ' , arr));
		}
	}
}