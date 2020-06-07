You have two arrays of integers.
 Write a piece of code to output an array that
 will only have elements found in one, but not both, arrays.

// Function for finding
// elements which are there
// in a[] but not in b[].
void findMissing(int a[], int b[],int n, int m) {
	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < m; j++)
			if (a[i] == b[j]) break;
			if (j == m)
			cout << a[i] << " ";
		}
 	}
}
