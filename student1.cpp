#include<iostream>
using namespace std;

class s2;
class s3;

class s1{
	int m1[5];
	float p1;
	public:
		void get_marks(){
			cout<<"Enter the marks of student s1 : ";
			cin>>m1[0]>>m1[1]>>m1[2]>>m1[3]>>m1[4];	
		}
		void calc_percentage(){
			p1=(m1[0]+m1[1]+m1[2]+m1[3]+m1[4])/5;
		}	
	friend void max(s1 x,s2 y,s2 z);
};

class s2{
	int m2[5];
	float p2;
	public:
		void get_marks(){
			cout<<"Enter the marks of student s2 : ";
			cin>>m2[0]>>m2[1]>>m2[2]>>m2[3]>>m2[4];
		}
		void calc_percentage(){
			p2=(m2[0]+m2[1]+m2[2]+m2[3]+m2[4])/5;
		}	
	friend void max(s1 x,s2 y,s3 z);
};

class s3{
	int m3[5];
	float p3;
	public:
		void get_marks(){
			cout<<"Enter the marks of student s3 : ";
			cin>>m3[0]>>m3[1]>>m3[2]>>m3[3]>>m3[4];
		}
		void calc_percentage(){
			p3=(m3[0]+m3[1]+m3[2]+m3[3]+m3[4])/5;
		}	
	friend void max(s1 x,s2 y,s3 z);
};

void swap(float *a,float *b){
	float temp = *a;
	*a=*b;
	*b=temp;
}

void max(s1 x,s2 y,s3 z){
	float max = x.p1 , middle = y.p2 , min=z.p3;
	if(max<middle){
		swap(&max,&middle);
	}
	if(middle<min){
		swap(&middle,&min);
	}
	if(max<middle){
		swap(&max,&middle);
	}
	cout<<"First : "<<max<<endl<<"Second : "<<middle<<endl<<"Third : "<<min<<endl;	
}

int main(){
	s1 m;
	s2 n;
	s3 o;
	m.get_marks();
	n.get_marks();
	o.get_marks();
	m.calc_percentage();
	m.calc_percentage();
	m.calc_percentage();
	max(m,n,o);
}
