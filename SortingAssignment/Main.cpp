#include <iostream>
#include <vector>
#include <ctime>


using namespace std;
// quickSortMiddle will take care of any sorting that uses the middle element as a pivot
void quickSortMiddle(vector<int>&, int, int);

// quickSortMEdian will take care of any sorting that uses the median of the first,last and middle elements as a pivot
//void quickSortMedian(vector<int>&, int, int);
void quickSortMedian(vector<int>& myVec,int start,int end);
int medianOfThreePartition(vector<int>& myVec,int p, int r);
int partition(vector<int>&, int, int);
void quickSortMiddleInsert(vector<int>& myVec, int num1, int num2);
void quickSortMedianInsert(vector<int>& myVec, int start, int end);



//vector<int> insertSort(vector<int> arr){
void insertSort(vector<int> &sortedArray);



int main()
{ 

	// ---------------------------TEST 0 - INSERTION--------------------------
/*
	vector<int> read;
	read.push_back(5);
	read.push_back(9);
	read.push_back(1);
	read.push_back(7);
	int p = 0;
	for (p = 0; p < read.size(); p++) {
		cout << read[p] << ",";
	}
	cout << endl;
	insertSort(read);
	for (p = 0; p < read.size(); p++) {
		cout << read[p] << ",";
	}
	cout << endl;
	cout << endl;
	*/
	/*
	//-------------------------------- TEST 1 - reading vector ---------------
	vector<int> v;
	int k;
	for(k=0; k<5; k++){
		v.push_back(k);
	}
	
	vector<int> v1(v);
	v.push_back(55);

	//print
	for(k=0; k<v.size(); k++){ cout << v[k] << ","; }
	cout << endl;
	for(k=0; k<v1.size(); k++){ cout << v1[k] << ","; }


	cout << endl << endl;
	*/
	//------------------------------------- END OF TEST 1

	srand(time(NULL));

	vector<int> myVec;

	//----------------------------------------- Generate random numbers
	int range = 5000000;
	int numLoops = 200000;

	for (int i = 0; i < numLoops; i++) {

		myVec.push_back((rand() % range) + 1); // Add 1 so, desire number is also include
											   //cout << myVector[i] << endl;

	}
	//-------------VISUAL TESTING ---------------------------
	vector<int> A = myVec;
	//----------------------------------------------------------
	//make 3 copies of the origianl vector 
	//do this by passing in the original vector into the constructor parameter
	//so when you modify the copies, you don't modify the original or the other copies
	vector<int> myVec1(myVec);
	vector<int> myVec2(myVec);
	vector<int> myVec3(myVec);
//----------------------------------------------- SORTING USING THE MIDDLE ELEMENT OF THE ARRAY AND SUBARRAY AS PIVOTS -------------------------------------------------------

	clock_t startTime, endTime;
	startTime = clock();
	quickSortMiddle(myVec, 0, numLoops);
	endTime = clock();
	cout << "Quick sort time, with pivot middle element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

//------------------------------------------ SORTING BY MEDIAN OF THE FIRST, LAST, AND MIDDLE ELEMENTS ---------------------------------------------

	startTime = clock();
	quickSortMedian(myVec1, 0, numLoops);
	endTime = clock();
	cout << "Quick sort time, with pivot median element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;



//------------------------------------------- SORTING BY MIDDLE ELEMENT OF THE ARRAY AND SUBARRAYS AS THE PIVOTS ------------------------------------
	//----------------------------------- WHEN THE SIZE OF ANY SUBARRAYS REDUCES TO LESS THAN 20, SORT THE SUBARRAY ----------------------------
	   //------------------------------------ USING INSERTION SORT.(INSERTION IMPLEMENTED SEPERATELY AND THEN CALLED ------------------------------
			//---------------------------- ------------------- INSIDE THE QUICKSORT ------------------------------------------------------------
	startTime = clock();
	quickSortMiddleInsert(myVec2, 0, numLoops);
	endTime = clock();
	cout << "Quick sort and insertion sort time, with pivot middle element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

//------------------------------------------- SORTING BY MEDIAN OF THE FIRST, LAST, MIDDLE ELEMENTS OF THE ARRAY AND SUBARRAYS AS THE PIVOTS ------------------------------------
	//----------------------------------- WHEN THE SIZE OF ANY SUBARRAYS REDUCES TO LESS THAN 20, SORT THE SUBARRAY ----------------------------
		//------------------------------------ USING INSERTION SORT.(INSERTION IMPLEMENTED SEPERATELY AND THEN CALLED ------------------------------
			//---------------------------- ------------------- INSIDE THE QUICKSORT ------------------------------------------------------------

	startTime = clock();
	quickSortMedianInsert(myVec3, 0, numLoops);
	endTime = clock();
	cout << "Quick sort and insertion sort time, with pivot median element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;




/*-------------------------------------------- VISUAL TESTING --------------------------------------------------
	int p = 0;
	int q = 10;

	cout << "======Original=======" << endl;
	for (auto e : A)
		cout << e << " ";
	cout << endl;

	quickSortMiddle(A, p, q);

	cout << "======Sorted=======" << endl;
	for (auto e : A)
		cout << e << " ";
	cout << endl;

*/
 //--------------------------------------- END OF VISUAL TESTING ---------------------------------------------

	system("pause");
	return 0;
}


void quickSortMiddle(vector<int>& myVec, int num1, int num2)
{
	int num;
	if (num1<num2)
	{
		num = partition(myVec, num1, num2);
		quickSortMiddle(myVec, num1, num);
		quickSortMiddle(myVec, num + 1, num2);
	}
	
}

void quickSortMiddleInsert(vector<int>& myVec, int num1, int num2)
{
	int num;
	if (myVec.size() > 20) {
		if (num1 < num2)
		{
			num = partition(myVec, num1, num2);
			quickSortMiddle(myVec, num1, num);
			quickSortMiddle(myVec, num + 1, num2);
		}
	
	}
	else {
		insertSort(myVec);
	}
}


int partition(vector<int>& vec, int num1, int num2)
{
	int num3 = vec[num1];
	int num4 = num1;

	for (int i = num1 + 1; i<num2; i++)
	{
		if (vec[i] <= num3)
		{
			num4 = num4 + 1;
			swap(vec[num4], vec[i]);
		}

	}

	swap(vec[num4], vec[num1]);


	return num4;
}


void quickSortMedian(vector<int>& myVec,int start,int end) {
    int q;
    if (end-start<2) return;
    q=medianOfThreePartition(myVec,start,end);
    quickSortMedian(myVec,start,q);
    quickSortMedian(myVec,q,end);
}

void quickSortMedianInsert(vector<int>& myVec, int start, int end) {
	int q;
	if (myVec.size() > 20) {
		if (end - start < 2) {
			// To exit the method
			return;
		}
		q = medianOfThreePartition(myVec, start, end);
		quickSortMedian(myVec, start, q);
	quickSortMedian(myVec, q, end);
	}
	else {
		insertSort(myVec);
	}
}

int medianOfThreePartition(vector<int>& myVec,int num1, int num2) {
	// Create shorter variables names
    int first=myVec[num1];
	int y=myVec[(num2-num1)/2+num1];
	int z=myVec[num2-1];
	int i=num1-1;
	int j=num2;

    if (y>first && y<z || y>z && y<first ) first=y;
    else if (z>first && z<y || z>y && z<first ) first=z;
    while (1) {
        do  {j--;} while (myVec[j] > first);
        do  {i++;} while (myVec[i] < first);
        if  (i < j) swap(myVec[i],myVec[j]);
        else return j+1;
    }
}

void insertSort(vector<int> &sortedArray) {

	unsigned int num;
	unsigned int num1;

	int max;

	for (num = 0; num<sortedArray.size(); num++) {
	// Start insert...

		for (num1 = num; num1<sortedArray.size(); num1++) {
			if (sortedArray[num] > sortedArray[num1]) {
				int temp;
				temp = sortedArray[num];
				sortedArray[num] = sortedArray[num1];
				sortedArray[num1] = temp;
			}

		}
	}
}


