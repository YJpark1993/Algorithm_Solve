#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    // 0 + arr[] �� ��� ����
    cout<<"accumulate ���� 1 : "<<accumulate(arr, arr+size, 0)<<endl;
    // 1 * arr[] �� ��� ����
    cout<<"accumulate ���� 2 : "<<accumulate(arr, arr+size, 1, multiplies<int>())<<endl;

    vector<int> v = {1,2,3,4,5,6};
    int carr[10];
    // deep copy , ������ vector ���� array�δ� ���� �Ұ���
    copy(arr, arr+size, carr);

    for(int i=0; i<size; i++) {
        cout<<carr[i]<<" ";
    }cout<<endl;

    // value�� ������ �����ش�
    int count_ = count(arr, arr+size, 2);
    cout<<count_<<endl;

    // value�� �ʱ�ȭ �����ش�.
    fill(arr, arr+size, 0);

     for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
