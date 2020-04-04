#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T,int N>
struct arr {
	T m[N];
};

//Вспомогательный шаблон
template<int n1, int n2, typename T1, typename T2 > auto sum(const arr<T1, n1>& a, const arr<T2, n2>& b) {
	return sum1(a, b, a.m[0] + b.m[0]);
	}

//Сумма векторов
template<int n1, int n2, typename T1, typename T2,typename T3 > arr<T3, ((n1 >= n2) ? n1 : n2)> sum1(const arr<T1, n1>& a, const arr<T2, n2>& b,T3 x)
{
	int i=0;
	const int n = ((n1 >= n2) ? n1 : n2);
	if (n1 < n2) {
		arr<T3, n> res;
		for (i = 0; i < n1; i++) {
			res.m[i] = a.m[i]+b.m[i];
		}
		for (i = n1; i < n2;i++) {
			res.m[i] = b.m[i];
		}
		return res;
	}
	else if(n1 > n2) {
		arr<T3, n> res;
		for (i = 0; i < n2; i++) {
			res.m[i] = b.m[i]+ a.m[i];
		}
		for (i = n2; i < n1;i++) {
			res.m[i] = a.m[i];
		}

		return res;
	}
	else if (n1 == n2) {
		arr<T3, n> res;
		for (i = 0; i < n2; i++) {
			res.m[i] = b.m[i] + a.m[i];
		}
		return res;
	}

}

//Разность векторов
template<int n1, int n2, typename T1, typename T2 > auto dif(const arr<T1, n1>& a, const arr<T2, n2>& b)
{
	const int n = ((n1 >= n2) ? n1 : n2);
	arr<T2, n2> bSub;
	int i = 0;
	for (i = 0; i < n2; i++) {
		bSub.m[i] = (-b.m[i]);
	}
	return sum1(a, bSub, a.m[0] + b.m[0]);
}

//Скалярное произведение векторов
template<int n1, int n2, typename T1, typename T2 > auto prd(const arr<T1, n1>& a, const arr<T2, n2>& b) {
	return prd1(a, b, a.m[0] + b.m[0]);
}
template<int n1, int n2, typename T1, typename T2, typename T3 > arr<T3, ((n1 >= n2) ? n1 : n2)> prd1(const arr<T1, n1>& a, const arr<T2, n2>& b, T3 x)
{
	int i = 0;
	const int n = ((n1 >= n2) ? n1 : n2);
	if (n1 < n2) {
		arr<T3, n> res;
		for (i = 0; i < n1; i++) {
			res.m[i] = a.m[i] * b.m[i];
		}
		for (i = n1; i < n2; i++) {
			res.m[i] = 0;
		}
		return res;
	}
	else if (n1 > n2) {
		arr<T3, n> res;
		for (i = 0; i < n2; i++) {
			res.m[i] = b.m[i] * a.m[i];
		}
		for (i = n2; i < n1; i++) {
			res.m[i] = 0;
		}

		return res;
	}
	else if (n1 == n2) {
		arr<T3, n> res;
		for (i = 0; i < n2; i++) {
			res.m[i] = b.m[i] * a.m[i];
		}
		return res;
	}

}

int main()
{
	arr<int, 2> p = {1,2};
	arr<double, 4> d = {1.6,2.5,3.3,4.56};
	
	cout << "Vector sum" << endl << endl ;
	auto k = sum(p, d);
	for (auto i:k.m) {
		cout << i << ' ';
	}

	cout << endl << endl << "Vector difference" << endl << endl ;
	auto k1 = dif(p, d);
	for (auto i : k1.m) {
		cout << i << ' ';
	}

	cout << endl << endl << "Vector scalar production" << endl << endl;
	auto k2 = prd(p, d);
	for (auto i : k2.m) {
		cout << i << ' ';
	}
	
	cout << endl;
}
