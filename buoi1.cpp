#include <bits/stdc++.h>
using namespace std;

/*Khai bao*/


typedef struct {
	int key;
	float otherfields;
} recordtype;

/*Doi cho*/
void Swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/*Selection Sort*/

void SelectionSort(recordtype a[], int n){
	int i,j, lowindex;
	keytype lowkey;
	for (i=0; i<=n-2; i++){
		lowkey = a[i].key;
		lowindex = i;
		for (j=i+1; j<=n-1; j++){
			if (a[j].key < lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		Swap(&a[i],&a[lowindex]);
	}
}

void Read_Data(recordtype a[], int *n){
	FILE *f;
	f=fopen("data.txt", "r");
	int i=0;
	if(f!=NULL)
	while (!feof(f)){
		fscanf(f,"%d%f",&a[i].key, &a[i].otherfields);
		i++;
	} else printf("Loi mo file\n");
	fclose(f);
	*n=i;
}
	
void Print_Data(recordtype a[], int n){
	int i;
	for(i=0;i<n;i++) 
	printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
}

void selection(recordtype a[],int n) {
	for(int i=0;i<n;i++) {
		int min = i;
		for(int j = i+1;j<n;j++){
			if(a[j].key < a[min].key){
				min = j;
			}
			swap(&a[i],&a[min]);
		}
	}
}
void insert(int a[],int n){
	for(int i = 0;i< n;i++) {
		int pos = i;
		while (a[pos-1] > a[pos]  && pos > 0) {
			int tmp = a[pos];
			a[pos] = a[pos-1];
			a[pos-1] = tmp;
			pos--;
		}
	}
}

void bubble(int a[],int n) {
	for(int i=0;i<=n-2;i++) {
		for(int j=n-1;j>=i+1;j--) {
			if(a[j] < a[j-1]) {
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
}

int findpivot(int a[],int i,int j) {
	int k = i + 1;
	int firstkey = a[i];
	while (k <= j && a[k] == firstkey) k++;
	if(k > j) return -1;
	if(a[k] > firstkey) return k;
	return i;
}

int partition (int a[],int i,int j,int pivot) {
	int l,r;
	l = i;
	r = j;
	while(l <= r) {
		while(a[l] < pivot) l++;
		while(a[r] >= pivot) r--;
		if(l<r) {
			int tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;
		}
	}
	return l;
}

void quicksort(int a[],int i ,int j) {
	int pivotindex = findpivot(a,i,j);
	if(pivotindex != -1 ){
		int pivot = a[pivotindex];
		int k = partition(a,i,j,pivot);
		quicksort(a,i,k-1);
		quicksort(a,k,j);
	}
}

// bien the
int partition(int a[],int i,int j) {
	int pivot = a[i];
	int l = i + 1;
	int r = j;
	while (l <= r) {
		while(l<=r && a[l] <= pivot) l++;
		while(l<=r && a[r] >= pivot) r--;
		if(l < r) swap(&a[l],&a[r])
	}
}



void pushdown (int a[],int first,int last) {
	int r = first;
	while (r <= (last - 1) / 2) {
		if (last == 2*r+1) {
			if(a[r] < a[last]) {
				int tmp = a[r];
				a[r] = a[last];
				a[last] = tmp;
			}
			r = last;
		}
		else {
			if(a[r] < a[2*r+1] && a[2*r+1] >= a[2*r + 2]){
				int tmp = a[r];
				a[r] = a[2*r + 1];
				a[2*r+1] = tmp;
				r = 2*r+1;
			}
			else {
				if(a[r] < a[2*r+2]) {
					int tmp = a[r];
					a[r] = a[2*r + 2];
					a[2*r+2] = tmp;
					r = 2*r+2;
				}
				else{
					r = last;
				}
			}
		}
	}
}

void heapsort(int a[],int n) {
	for(int i=(n-2) / 2;i>= 0;i--) {
		pushdown(a,i,n-1);
	}
	for(int i = n-1;i>=2;i--) {
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		pushdown(a,0,i-1);
	}
	int tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	
}

int main () {
	FILE *f;
    f = fopen("D:/CT174_TH_PTTKTT/Sapxep/data.txt", "r");
    if(f == NULL){
        printf("Cannot open file !\n");
        return 0;
    }
    int a[1000];
	float b[1000];
    int n = 0,m = 0;
    while(fscanf(f,"%d%f",&a[n],&b[m]) == 2) {
    	n++;
    	m++;
	}
	heapsort(a,n);
	for(int i=0;i<n;i++) {
		cout << a[i] << " ";
	}
	
    fclose( f );
}
