#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
const int blank=50;//���������޸Ĵ˴� 
const int bit=8;
using namespace std;
//���� 
void tblank();//�ո��ʼ������ 
void list();//�˵�����
void operation();//�������� 
int TwoComcode();//�����Ʋ��� 
long long TwoChangeEight(long long begin);//������ת���˽��� 
long long TwoChangeNine(long long begin);//������ת��ʮ���� 
string TwoChangeSixteen(long long begin);//������ת��ʮ������ 
long long EightChangeTwo(long long);//�˽���ת�������� 
long long EightChangeNine(long long begin);//�˽���ת��ʮ���� 
string EightChangeSixteen(long long begin);//�˽���ת��ʮ������ 
long long NineChangeTwo(long long begin);//ʮ����ת�������� 
int NineChangeEight(int begin);//ʮ����ת���˽��� 
string NineChangeSixteen(int begin);//ʮ����ת��ʮ������ 
long long SixteenChangeTwo(string begin);//ʮ������ת�������� 
long long SixteenChangeEight(string begin);//ʮ������ת���˽��� 
int SixteenChangeNine(string s);//ʮ������ת��ʮ���� 
//�ո���ƽ������ 
char bs[blank];
//������ 
int main(){
	tblank();//�ո��ʼ�� 
	operation();//�������� 
	return 0;
}
//ʮ������ת��Ϊ�˽���
long long SixteenChangeEight(string x){
	return NineChangeEight(SixteenChangeNine(x));
} 
//ʮ������ת��Ϊ������
long long SixteenChangeTwo(string x){
  return NineChangeTwo(SixteenChangeNine(x));
} 
//�˽���ת��Ϊʮ������ 
string EightChangeSixteen(long long x){
	return NineChangeSixteen(EightChangeNine(x)); 
}
//�˽���ת��Ϊ������
long long EightChangeTwo(long long x){
	return	NineChangeTwo(EightChangeNine(x));
	
} 
//������תʮ������
string TwoChangeSixteen(long long x){
	return NineChangeSixteen(TwoChangeNine(x));
} 
//������ת�˽���
long long TwoChangeEight(long long x){
	return NineChangeEight(TwoChangeNine(x));
} 
//ʮ������ת��Ϊʮ����
int SixteenChangeNine(string x){
	map<char,int> mp;
	for(int i=10;i<=15;i++){
		mp['A'+i-10]=i;
	}
	int answer=0,k=0;
	for(int i=x.length()-1;i>=0;i--){
		if(x[i]-'0'<=9&&x[i]-'0'>=0){
			answer+=(x[i]-'0')*pow(16,k);
		}else{
			answer+=mp[x[i]]*pow(16,k);
		}
		k++;
	}
	return answer;
} 
//�˽���ת��Ϊʮ����
long long EightChangeNine(long long x){
	long long answer=0;
	int k=0;
	while(x){
		answer+=x%10*pow(8,k);
		x/=10;
		k++; 
	}
	return answer;
} 
//������ת��Ϊʮ����
long long TwoChangeNine(long long x){
	long long answer=0;
	int k=0;
	while(x){
		answer+=x%10*pow(2,k);
		x/=10;
		k++; 
	}
	return answer;
} 
//ʮ����ת��Ϊ�˽��� 
int NineChangeEight(int x){
	char str[1000];
	sprintf(str,"%o",x);
	return atoi(str);
	/*֧�ָ���ת����Χ��С 
	int answer=0,a[100],b[100];
	memset(a,0,sizeof(a)); 
	int two=NineChangeTwo(x);//���������
	//cout<<"�����ƣ�"<<two<<endl;
	//�������鴦�� 
	int len=0;
	while(two){
		a[len++]=two%10;
		two/=10;
	}
	//��λһ���˽��� 
	int con=0,sum=0,k=0;
	for(int i=0;i<bit;i++){
		sum+=a[i]*pow(2,con);
		con++;
		if(con==3){
			con=0;
			b[k++]=sum;
			sum=0;
		}
	}
	//����λ 
	sum=0,con=0;
	for(int i=k*3;i<bit;i++){
		sum+=a[i]*pow(2,con);
		con++;
	}
	b[k]=sum;
	//ת��Ϊ���� 
	int tt=1;
	for(int i=0;i<k+1;i++){
		answer=answer+b[i]*tt;
		tt*=10;
	int answer=0,
	}*/
}
//ʮ����ת��Ϊʮ�����ƺ��� 
string	NineChangeSixteen(int x){
	char str[1000];
	sprintf(str,"%x",x);
	string s(str);
	return s;
}
//������Ʋ��뺯�� 
long long TwoComcode(long long x){
	x*=-1;
	long long len=0,a[1000];
	memset(a,0,sizeof(a));//��ʼ������
	//����ԭ�� 
	while(x){
		a[len]=x%2;
		x/=2;
		len++;
	}
	//���㷴�� 
	for(int i=0;i<bit;i++){
		a[i]=a[i]==0?1:0;
	}
	//���㲹�� 
	for(int i=0;i<bit;i++){
		if(a[i]==0){
			a[i]=1;
		}
	}
	//ת��Ϊ���� 
	long long t=1,answer=0;
	for(int i=0;i<bit;i++){
		answer=answer+a[i]*t;
		t*=10;
	}
	return answer;
	
}
//ʮ����ת��Ϊ�����ƺ���
long long NineChangeTwo(long long x){
	if(x>=0){//����
		long long answer=0,pp=1; 
		while(x){
			answer+=x%2*pp;
			pp*=10;
			x/=2;
		}
		return answer;
	}else{//���� 
		return  TwoComcode(x);
	}
} 
//���ƽ����������� 
void tblank(){
	memset(bs,' ',sizeof(bs));
	bs[blank]='\0';
} 
//�˵����� 
void list(){
	printf("%s++++++++++++++����ת����++++++++++++++\n\n",bs);
	printf("     %s1.������ת��Ϊ�˽���\n\n",bs);
	printf("     %s2.������ת��Ϊʮ����\n\n",bs);
	printf("     %s3.������ת��Ϊʮ������\n\n",bs);
	
	printf("     %s4.�˽���ת��Ϊ������\n\n",bs);
	printf("     %s5.�˽���ת��Ϊʮ����\n\n",bs);
	printf("     %s6.�˽��ƽ���ת��Ϊʮ������\n\n",bs);
		
	printf("     %s7.ʮ����ת��Ϊ������\n\n",bs);
	printf("     %s8.ʮ����ת��Ϊ�˽���\n\n",bs);
	printf("     %s9.ʮ����ת��Ϊʮ������\n\n",bs);
	
	printf("     %s10.ʮ������ת��Ϊ������\n\n",bs);
	printf("     %s11.ʮ������ת��Ϊ�˽���\n\n",bs);
	printf("     %s12.ʮ������ת��Ϊʮ����\n\n",bs);
	printf("        %s������ѡ�������",bs);
}
//�������� 
void operation(){
	while(1){
		system("cls");
		list(); //��ӡ�˵� 
	    int operation;
	    cin>>operation;
	    switch(operation){
	    	case 1:{//������ת��Ϊ�˽���
	    		system("cls");
	    		printf("%s*************������ת��Ϊ�˽���*************\n\n",bs);
				long long end,begin;
	    		printf("\n\n%s�������������:",bs);
	    		scanf("%lld",&begin);
	    		end=TwoChangeEight(begin);
	    		printf("\n\n%s%lld�İ˽��� = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}
	    	case 2:{//������ת��Ϊʮ����
	    		system("cls");
	    		printf("%s*************������ת��Ϊʮ����*************\n\n",bs);
				long long end,begin;
	    		printf("\n\n%s�������������:",bs);
	    		scanf("%lld",&begin);
	    		end=TwoChangeNine(begin);
	    		printf("\n\n%s%lld��ʮ���� = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}
	    	case 3:{//������ת��Ϊʮ������
	    		system("cls");
	    		printf("%s*************������ת��Ϊʮ������*************\n\n",bs);
	    		long long begin;
				string end;
	    		printf("\n\n%s�������������:",bs);
	    		scanf("%lld",&begin);
	    		end=TwoChangeSixteen(begin);
	    		char str[10000];
	    		strcpy(str,end.c_str());
	    		for(int i=0;i<strlen(str);i++){
	    			if(str[i]>='a'&&str[i]<='z'){
	    				str[i]-='a'-'A';
	    			}
	    		}
	    		printf("\n\n%s%lld��ʮ������ = %s\n\n\n",bs,begin,str);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	} 
	    	case 4:{//�˽���ת��Ϊ������
	    		system("cls");
	    		printf("%s*************�˽���ת��Ϊ������*************\n\n",bs);
				long long end,begin;
	    		printf("\n\n%s������˽�����:",bs);
	    		scanf("%lld",&begin);
	    		end=EightChangeTwo(begin);
	    		printf("\n\n%s%lld�Ķ����� = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}
	    	case 5:{//�˽���ת��Ϊʮ����
	    		system("cls");
	    		printf("%s*************�˽���ת��Ϊʮ����*************\n\n",bs);
				long long end,begin;
	    		printf("\n\n%s������˽�����:",bs);
	    		scanf("%lld",&begin);
	    		end=EightChangeNine(begin);    
	    		printf("\n\n%s%lld��ʮ���� = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();    
				getchar();
	    		system("cls");
	    		break;
	    	}
	    	case 6:{//�˽���ת��Ϊʮ������
	    		system("cls");
	    		printf("%s*************�˽���ת��Ϊʮ������*************\n\n",bs);
	    		long long begin;
				string end;
	    		printf("\n\n%s������˽�����:",bs);
	    		scanf("%lld",&begin);
	    		end=EightChangeSixteen(begin);
	    		char str[10000];
	    		strcpy(str,end.c_str());
	    		for(int i=0;i<strlen(str);i++){
	    			if(str[i]>='a'&&str[i]<='z'){
	    				str[i]-='a'-'A';
	    			}
	    		}
	    		printf("\n\n%s%lld��ʮ������ = %s\n\n\n",bs,begin,str);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	} 
	    	case 7:{//ʮ����ת��Ϊ������
	    		system("cls");
	    		printf("%s*************ʮ����ת��Ϊ������*************\n\n",bs);
	    		int begin,end;
	    		printf("\n\n%s������ʮ������:",bs);
	    		cin>>begin;
	    		end=NineChangeTwo(begin);
	    		printf("\n\n%s%d�Ķ����� = %016d\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}
			case 8:{//ʮ����ת��Ϊ�˽���
	    		system("cls");
	    		printf("%s*************ʮ����ת��Ϊ�˽���*************\n\n",bs);
	    		int begin,end;
	    		printf("\n\n%s������ʮ������:",bs);
	    		cin>>begin;
	    		end=NineChangeEight(begin);
	    		printf("\n\n%s%d�İ˽��� = %d\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}  
	    	case 9:{//ʮ����ת��Ϊʮ������
	    		system("cls");
	    		printf("%s*************ʮ����ת��Ϊʮ������*************\n\n",bs);
	    		int begin;
				string end;
	    		printf("\n\n%s������ʮ������:",bs);
	    		cin>>begin;
	    		end=NineChangeSixteen(begin);
	    		char str[1000];
	    		strcpy(str,end.c_str());
	    		for(int i=0;i<strlen(str);i++){
	    			if(str[i]>='a'&&str[i]<='z'){
	    				str[i]-='a'-'A';
	    			}
	    		}
	    		printf("\n\n%s%d��ʮ������ = %s\n\n\n",bs,begin,str);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	} 
	    	case 10:{//ʮ������ת��Ϊ������
	    		system("cls");
	    		printf("%s*************ʮ������ת��Ϊ������*************\n\n",bs);
	    		long long end;
	    		char begin[100];
	    		printf("\n\n%s������ʮ��������:",bs);
	    		scanf("%s",begin); 
	    		string s(begin);
	    		end=SixteenChangeTwo(s);
	    		printf("\n\n%s%s�Ķ����� = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
				getchar();    
				getchar();
	    		system("cls");
	    		break; 
	    	} 
	    	case 11:{//ʮ������ת��Ϊ�˽���}    
	    		system("cls");
	    		printf("%s*************ʮ������ת��Ϊ�˽���*************\n\n",bs);
	    		long long end;
	    		char begin[100];
	    		printf("\n\n%s������ʮ��������:",bs);
	    		scanf("%s",begin); 
	    		string s(begin);
	    		end=SixteenChangeEight(begin);;
	    		printf("\n\n%s%s�İ˽��� = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	} 
	    	case 12:{//ʮ������ת��Ϊʮ����
	    		system("cls");
	    		printf("%s*************ʮ������ת��Ϊʮ����*************\n\n",bs);
	    		int end;
	    		char begin[100];
	    		printf("\n\n%s������ʮ��������:",bs);
	    		scanf("%s",begin); 
	    		string s(begin);
	    		end=SixteenChangeNine(s);
	    		printf("\n\n%s%s��ʮ���� = %d\n\n\n",bs,begin,end);
	    		printf("\n\n%s<�س����ز˵�>",bs);
	    		getchar();
	    		getchar();   
				system("cls");          	
				break;
	    	}  
			default :{
				break;
	 		}
		}   
	}
}
