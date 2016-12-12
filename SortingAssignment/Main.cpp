#include <iostream>
#include <vector>
#include <ctime>


using namespace std;
// quickSortMiddle will take care of any sorting that uses the middle element as a pivot
void quickSortMiddle(vector<int>&, int, int);

// quickSortMEdian will take care of any sorting that uses the median of the first,last and middle elements as a pivot
void quickSortMedian();
int partition(vector<int>&, int, int);



int main()
{ 
	srand(time(NULL));

	vector<int> myVec;

	//----------------------------------------- Generate random numbers
	int range = 5000000;
	int numLoops = 100000;

	for (int i = 0; i < numLoops; i++) {

		myVec.push_back((rand() % range) + 1); // Add 1 so, desire number is also include
											   //cout << myVector[i] << endl;

	}
	//-------------VISUAL TESTING ---------------------------
	//vector<int> A = myVec;
	//----------------------------------------------------------
	vector<int> myVec1 = myVec;
	vector<int> myVec2 = myVec;
	vector<int> myVec3 = myVec;
//----------------------------------------------- SORTING USING THE MIDDLE ELEMENT OF THE ARRAY AND SUBARRAY AS PIVOTS -------------------------------------------------------

	clock_t startTime, endTime;
	startTime = clock();
	quickSortMiddle(myVec, 0, numLoops);
	endTime = clock();
	cout << "Quick sort time, with pivot middle element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

//------------------------------------------ SORTING BY MEDIAN OF THE FIRST, LAST, AND MIDDLE ELEMENTS ---------------------------------------------

	startTime = clock();
	quickSortMiddle(myVec1, 0, numLoops);
	endTime = clock();
	cout << "Quick sort time, with pivot median element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;



//------------------------------------------- SORTING BY MIDDLE ELEMENT OF THE ARRAY AND SUBARRAYS AS THE PIVOTS ------------------------------------
	//----------------------------------- WHEN THE SIZE OF ANY SUBARRAYS REDUCES TO LESS THAN 20, SORT THE SUBARRAY ----------------------------
	   //------------------------------------ USING INSERTION SORT.(INSERTION IMPLEMENTED SEPERATELY AND THEN CALLED ------------------------------
			//---------------------------- ------------------- INSIDE THE QUICKSORT ------------------------------------------------------------
	startTime = clock();
	quickSortMiddle(myVec2, 0, numLoops);
	endTime = clock();
	cout << "Quick sort and insertion sort time, with pivot middle element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

//------------------------------------------- SORTING BY MEDIAN OF THE FIRST, LAST, MIDDLE ELEMENTS OF THE ARRAY AND SUBARRAYS AS THE PIVOTS ------------------------------------
	//----------------------------------- WHEN THE SIZE OF ANY SUBARRAYS REDUCES TO LESS THAN 20, SORT THE SUBARRAY ----------------------------
		//------------------------------------ USING INSERTION SORT.(INSERTION IMPLEMENTED SEPERATELY AND THEN CALLED ------------------------------
			//---------------------------- ------------------- INSIDE THE QUICKSORT ------------------------------------------------------------

	startTime = clock();
	quickSortMiddle(myVec3, 0, numLoops);
	endTime = clock();
	cout << "Quick sort and insertion sort time, with pivot median element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;




/*-------------------------------------------- VISUAL TESTING --------------------------------------------------
	int p = 0;
	int q = 10;

	cout << "======Original=======" << endl;
	for (auto e : A)
		cout << e << " ";
	cout << endl;

	quickSort(A, p, q);

	cout << "======Sorted=======" << endl;
	for (auto e : A)
		cout << e << " ";
	cout << endl;

*///--------------------------------------- END OF VISUAL TESTING ---------------------------------------------

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

void quickSortMedian() {

}


