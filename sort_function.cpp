void Sort::select_sort(string list[], int n) { // ��������
	int least;
	string tmp;
	for(int i=0; i<n-1; i++) {
		least = i;	// ���� ���� ��������
		for(int j=i+1; j<n; j++) {
			// �� ���� �ε����� ã�´�
			if(compareString(list[least],list[j])) {
				least = j;
			}
		}
		// swap ����
		tmp = list[i];
		list[i] = list[least];
		list[least] = tmp;
	}
}
void Sort::insertion_sort(string list[], int n) { // ��������
	int i,j;
	string key;

	for(i=1; i<n; i++) {
		key = list[i];	// key�� ���� �������� ��ġ�� ã�Ƴ��� �����Ѵ�.
		for(j=i-1; j>=0 && compareString(list[j],key); j--) {
			list[j+1] = list[j];
		}
		list[j+1] = key;
	}

}
void Sort::bubble_sort(string list[], int n) { // ��������
	string tmp;
	// �ٷ� ���� ���ҿ� ���ؼ� �ϳ��ϳ� ������ ã�´�
	for(int i=n-1; i>0; i--) {
		for(int j=0; j<i; j++) {
			if(compareString(list[j],list[j+1])) {
				tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
			}
		}
	}
}
void Sort::merge_sort(string list[], int left, int n) {	//�պ�����
	if(left<n) {
		int mid = (left+n)/2;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, n);
		merge(list, left, mid, n);
	}

}
void Sort::merge(string list[], int left, int mid, int n) { //�պ�����
	int i,j,result;
	// mid �����ŭ �����ؼ� ���� �� �պ��Ѵ�
	for(i=left, j=mid+1, result=left; i<=mid && j<=n;) {
		if(list[i] <= list[j]) {
			mergeList[result++] = list[i++];
		}else {
			mergeList[result++] = list[j++];
		}
	}
	if(i>mid) {
		for(int p=j; p<=n; p++) {
			mergeList[result++] = list[p];
		}
	}else {
		for(int p=i; p<=mid; p++) {
			mergeList[result++] = list[p];
		}
	}
	for(int p=left; p <=n; p++) {
		list[p] = mergeList[p];
	}

}
void Sort::quick_sort(string list[], int left, int right) {	//������
	int low = left, high = right+1;
	string pivot = list[left];
	// pivot�� �������� ���ʰ� ���������� ������ ���Ѵ�
	if(left<right) {
		do {
			do {low++;}
			while(compareString(pivot,list[low]));
			do {high--;}
			while(compareString(list[high],pivot));
			if(low<high) {
				swap(list[low],list[high]);
			}
		}while(low<high);
		swap(list[left],list[high]);
		quick_sort(list,left,high-1);
		quick_sort(list,high+1,right);
	}

}
void Sort::heap_sort(string list[], int n) { //������
	Heap heap;
	// ���ȿ��� �ּҰ��� �������½����� �����Ѵ�
	for(int i=0; i<n; i++) {
		heap.insertMinHeap(list[i]);
	}
	for(int i=0; i<n; i++) {
		list[i] = heap.deleteMinHeap();
	}
}
