import java.util.Scanner;

// 17MCME08 Buncy shaddai

class sets
{
	static int	MAX = 50;

	public static void main(String[] args)
	{
		int	opt, n1, n2, n3, val;
		int 	seta[] = new int[MAX];
		int 	setb[] = new int[MAX];
		int	setc[] = new int[MAX];
		boolean    check;

		Scanner sc = new Scanner (System.in);

		System.out.println("Enter the number of elements in setA: ");
		n1 = sc.nextInt();
		create_set(seta, n1);

		System.out.println("Enter the number of elements in setB: ");
		n2 = sc.nextInt();
		create_set(setb, n2);

		opt = menu();
		switch (opt)
		{
			case 1:
				n3 = set_union(seta, setb, setc, n1, n2);
				print_set(setc, n3);
				break;
			case 2:
				n3 = set_intersection(seta, setb, setc, n1, n2);
				print_set(setc, n3);
				break;
			case 3:
				n3 = set_difference(seta, setb, setc, n1, n2);
				print_set(setc, n3);
				break;
			case 4:
				n3 = set_sym_diff(seta, setb, setc, n1, n2);
				print_set(setc, n3);
				break;
			case 5:
				System.out.println("Enter the value: ");
				val = sc.nextInt();
				check = is_member(seta, n1, val);
				if (check)
				{
					System.out.println("Is a member\n");
				}
				else
				{
					System.out.println("Not a member\n");
				}
				break;
			case 6:
				check = subset(seta, setb, n1, n2);
				if (check)
				{
					System.out.println("Is a subset\n");
				}
				else
				{
					System.out.println("Not a subset\n");
				}
				break;
			case 7:
				check = superset(seta, setb, n1, n2);
				if (check)
				{
					System.out.println("Is a superset\n");
				}
				else
				{
					System.out.println("Not a superset\n");
				}
				break;
			case 8:
				return;
		}

		return ;
	}

	static void print_set(int set[], int n)
	{
		int        i;


		System.out.print("{");
		for (i = 0; i < n; i++)
		{
			System.out.print(set[i] + ", ");
		}
		System.out.println("}");

		return ;
	}

	static void create_set(int set[], int n)
	{
		int        i = 0, num;
		Scanner sc = new Scanner(System.in);

		while (i < n)
		{
			num = sc.nextInt();
			if (!is_member(set, n, num))
			 {
				set[i] = num;
				i++;
			}
		}

		return ;
	}

	static boolean is_member(int set[], int n, int val)
	{
		int        i;

		for (i = 0; i < n; i++)
		{
			if (set[i] == val)
			{
				return true;
			}
		}

		return false;
	}

	static int set_union(int seta[], int setb[], int setc[], int n1, int n2)
	{
		int        i, k;

		for (i = 0; i < n1; i++)
		{
			setc[i] = seta[i];
		}

		k = i;
		for (i = 0; i < n2; i++)
		{
			if (!is_member(setc, k, setb[i]))
			{
				setc[k] = setb[i];
				k++;
			}
		}

		return k;
	}

	static int set_intersection(int seta[], int setb[], int setc[], int n1, int n2)
	{
		int        i, k = 0;

		for (i = 0; i < n1; i++)
		{
			if (is_member(setb, n2, seta[i]))
			{
				setc[k] = seta[i];
				k++;
			}
		}

		return k;
	}

	static int set_difference(int seta[], int setb[], int setc[], int n1, int n2)
	{
		int        i, k = 0;

		for (i = 0; i < n1; i++)
		{
			if (!is_member(setb, n2, seta[i]))
			{
				setc[k] = seta[i];
				k++;
			}
		}

		return k;
	}

	static int set_sym_diff(int seta[], int setb[], int setc[], int n1, int n2)
	{
		int	tn1, tn2;
		int	ts1[] = new int[MAX];
		int	ts2[] = new int[MAX];

		tn1 = set_difference(seta, setb, ts1, n1, n2);
		tn2 = set_difference(setb, seta, ts2, n2, n1);
		return set_union(ts1, ts2, setc, tn1, tn2);
	}

	static boolean subset(int seta[], int setb[], int n1, int n2)
	{
		int        i, j, count = 0;

		for (i = 0; i < n1; i++)
		{
			for (j = 0; j < n2; j++)
			{
				if (seta[i] == setb[j])
				{
					count = count + 1;
				}
			}
		}

		if (count == n1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static boolean superset(int seta[], int setb[], int n1, int n2)
	{
		int        i, j, count = 0;

		for (i = 0; i < n2; i++)
		{
			for (j = 0; j < n1; j++)
			{
				if (seta[i] == setb[j])
				{
					count = count + 1;
				}
			}
		}

		if (count == n2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static int menu()
	{
		int       option;
		Scanner sc = new Scanner(System.in);

		System.out.println("\n----------------------------\n");
		System.out.println("        Set operations        \n");
		System.out.println("----------------------------  \n");
		System.out.println("1) Union\n");
		System.out.println("2) Intersection\n");
		System.out.println("3) Difference\n");
		System.out.println("4) Symmteric Difference\n");
		System.out.println("5) Is member\n");
		System.out.println("6) Is subset\n");
		System.out.println("7) Is superset\n");
		System.out.println("8) Exit\n");

		System.out.println("Enter your choice: ");
		option = sc.nextInt();

		return option;
	}

}
