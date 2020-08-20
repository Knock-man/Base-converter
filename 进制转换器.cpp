#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
const int blank=50;//控制缩进修改此处 
const int bit=8;
using namespace std;
//函数 
void tblank();//空格初始化函数 
void list();//菜单函数
void operation();//操作函数 
int TwoComcode();//二进制补码 
long long TwoChangeEight(long long begin);//二进制转化八进制 
long long TwoChangeNine(long long begin);//二进制转化十进制 
string TwoChangeSixteen(long long begin);//二进制转化十六进制 
long long EightChangeTwo(long long);//八进制转化二进制 
long long EightChangeNine(long long begin);//八进制转化十进制 
string EightChangeSixteen(long long begin);//八进制转化十六进制 
long long NineChangeTwo(long long begin);//十进制转化二进制 
int NineChangeEight(int begin);//十进制转化八进制 
string NineChangeSixteen(int begin);//十进制转化十六进制 
long long SixteenChangeTwo(string begin);//十六进制转化二进制 
long long SixteenChangeEight(string begin);//十六进制转化八进制 
int SixteenChangeNine(string s);//十六进制转换十进制 
//空格控制界面对齐 
char bs[blank];
//主函数 
int main(){
	tblank();//空格初始化 
	operation();//操作函数 
	return 0;
}
//十六进制转化为八进制
long long SixteenChangeEight(string x){
	return NineChangeEight(SixteenChangeNine(x));
} 
//十六进制转化为二进制
long long SixteenChangeTwo(string x){
  return NineChangeTwo(SixteenChangeNine(x));
} 
//八进制转化为十六进制 
string EightChangeSixteen(long long x){
	return NineChangeSixteen(EightChangeNine(x)); 
}
//八进制转化为二进制
long long EightChangeTwo(long long x){
	return	NineChangeTwo(EightChangeNine(x));
	
} 
//二级制转十六进制
string TwoChangeSixteen(long long x){
	return NineChangeSixteen(TwoChangeNine(x));
} 
//二级制转八进制
long long TwoChangeEight(long long x){
	return NineChangeEight(TwoChangeNine(x));
} 
//十六进制转换为十进制
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
//八进制转化为十进制
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
//二进制转化为十进制
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
//十进制转化为八进制 
int NineChangeEight(int x){
	char str[1000];
	sprintf(str,"%o",x);
	return atoi(str);
	/*支持负数转化范围较小 
	int answer=0,a[100],b[100];
	memset(a,0,sizeof(a)); 
	int two=NineChangeTwo(x);//算出二进制
	//cout<<"二进制："<<two<<endl;
	//放入数组处理 
	int len=0;
	while(two){
		a[len++]=two%10;
		two/=10;
	}
	//三位一个八进制 
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
	//多余位 
	sum=0,con=0;
	for(int i=k*3;i<bit;i++){
		sum+=a[i]*pow(2,con);
		con++;
	}
	b[k]=sum;
	//转换为数字 
	int tt=1;
	for(int i=0;i<k+1;i++){
		answer=answer+b[i]*tt;
		tt*=10;
	int answer=0,
	}*/
}
//十进制转化为十六进制函数 
string	NineChangeSixteen(int x){
	char str[1000];
	sprintf(str,"%x",x);
	string s(str);
	return s;
}
//求二进制补码函数 
long long TwoComcode(long long x){
	x*=-1;
	long long len=0,a[1000];
	memset(a,0,sizeof(a));//初始化数组
	//计算原码 
	while(x){
		a[len]=x%2;
		x/=2;
		len++;
	}
	//计算反码 
	for(int i=0;i<bit;i++){
		a[i]=a[i]==0?1:0;
	}
	//计算补码 
	for(int i=0;i<bit;i++){
		if(a[i]==0){
			a[i]=1;
		}
	}
	//转化为整数 
	long long t=1,answer=0;
	for(int i=0;i<bit;i++){
		answer=answer+a[i]*t;
		t*=10;
	}
	return answer;
	
}
//十进制转化为二进制函数
long long NineChangeTwo(long long x){
	if(x>=0){//正数
		long long answer=0,pp=1; 
		while(x){
			answer+=x%2*pp;
			pp*=10;
			x/=2;
		}
		return answer;
	}else{//负数 
		return  TwoComcode(x);
	}
} 
//控制界面缩进函数 
void tblank(){
	memset(bs,' ',sizeof(bs));
	bs[blank]='\0';
} 
//菜单函数 
void list(){
	printf("%s++++++++++++++进制转换器++++++++++++++\n\n",bs);
	printf("     %s1.二进制转化为八进制\n\n",bs);
	printf("     %s2.二进制转化为十进制\n\n",bs);
	printf("     %s3.二进制转化为十六进制\n\n",bs);
	
	printf("     %s4.八进制转化为二进制\n\n",bs);
	printf("     %s5.八进制转化为十进制\n\n",bs);
	printf("     %s6.八进制进制转化为十六进制\n\n",bs);
		
	printf("     %s7.十进制转化为二进制\n\n",bs);
	printf("     %s8.十进制转化为八进制\n\n",bs);
	printf("     %s9.十进制转化为十六进制\n\n",bs);
	
	printf("     %s10.十六进制转化为二进制\n\n",bs);
	printf("     %s11.十六进制转化为八进制\n\n",bs);
	printf("     %s12.十六进制转换为十进制\n\n",bs);
	printf("        %s请输入选择操作：",bs);
}
//操作函数 
void operation(){
	while(1){
		system("cls");
		list(); //打印菜单 
	    int operation;
	    cin>>operation;
	    switch(operation){
	    	case 1:{//二进制转化为八进制
	    		system("cls");
	    		printf("%s*************二进制转化为八进制*************\n\n",bs);
				long long end,begin;
	    		printf("\n\n%s请输入二进制数:",bs);
	    		scanf("%lld",&begin);
	    		end=TwoChangeEight(begin);
	    		printf("\n\n%s%lld的八进制 = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}
	    	case 2:{//二进制转化为十进制
	    		system("cls");
	    		printf("%s*************二进制转化为十进制*************\n\n",bs);
				long long end,begin;
	    		printf("\n\n%s请输入二进制数:",bs);
	    		scanf("%lld",&begin);
	    		end=TwoChangeNine(begin);
	    		printf("\n\n%s%lld的十进制 = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}
	    	case 3:{//二进制转化为十六进制
	    		system("cls");
	    		printf("%s*************二进制转化为十六进制*************\n\n",bs);
	    		long long begin;
				string end;
	    		printf("\n\n%s请输入二进制数:",bs);
	    		scanf("%lld",&begin);
	    		end=TwoChangeSixteen(begin);
	    		char str[10000];
	    		strcpy(str,end.c_str());
	    		for(int i=0;i<strlen(str);i++){
	    			if(str[i]>='a'&&str[i]<='z'){
	    				str[i]-='a'-'A';
	    			}
	    		}
	    		printf("\n\n%s%lld的十六进制 = %s\n\n\n",bs,begin,str);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	} 
	    	case 4:{//八进制转化为二进制
	    		system("cls");
	    		printf("%s*************八进制转化为二进制*************\n\n",bs);
				long long end,begin;
	    		printf("\n\n%s请输入八进制数:",bs);
	    		scanf("%lld",&begin);
	    		end=EightChangeTwo(begin);
	    		printf("\n\n%s%lld的二进制 = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}
	    	case 5:{//八进制转化为十进制
	    		system("cls");
	    		printf("%s*************八进制转化为十进制*************\n\n",bs);
				long long end,begin;
	    		printf("\n\n%s请输入八进制数:",bs);
	    		scanf("%lld",&begin);
	    		end=EightChangeNine(begin);    
	    		printf("\n\n%s%lld的十进制 = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();    
				getchar();
	    		system("cls");
	    		break;
	    	}
	    	case 6:{//八进制转化为十六进制
	    		system("cls");
	    		printf("%s*************八进制转化为十六进制*************\n\n",bs);
	    		long long begin;
				string end;
	    		printf("\n\n%s请输入八进制数:",bs);
	    		scanf("%lld",&begin);
	    		end=EightChangeSixteen(begin);
	    		char str[10000];
	    		strcpy(str,end.c_str());
	    		for(int i=0;i<strlen(str);i++){
	    			if(str[i]>='a'&&str[i]<='z'){
	    				str[i]-='a'-'A';
	    			}
	    		}
	    		printf("\n\n%s%lld的十六进制 = %s\n\n\n",bs,begin,str);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	} 
	    	case 7:{//十进制转化为二进制
	    		system("cls");
	    		printf("%s*************十进制转化为二进制*************\n\n",bs);
	    		int begin,end;
	    		printf("\n\n%s请输入十进制数:",bs);
	    		cin>>begin;
	    		end=NineChangeTwo(begin);
	    		printf("\n\n%s%d的二进制 = %016d\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}
			case 8:{//十进制转化为八进制
	    		system("cls");
	    		printf("%s*************十进制转化为八进制*************\n\n",bs);
	    		int begin,end;
	    		printf("\n\n%s请输入十进制数:",bs);
	    		cin>>begin;
	    		end=NineChangeEight(begin);
	    		printf("\n\n%s%d的八进制 = %d\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	}  
	    	case 9:{//十进制转化为十六进制
	    		system("cls");
	    		printf("%s*************十进制转化为十六进制*************\n\n",bs);
	    		int begin;
				string end;
	    		printf("\n\n%s请输入十进制数:",bs);
	    		cin>>begin;
	    		end=NineChangeSixteen(begin);
	    		char str[1000];
	    		strcpy(str,end.c_str());
	    		for(int i=0;i<strlen(str);i++){
	    			if(str[i]>='a'&&str[i]<='z'){
	    				str[i]-='a'-'A';
	    			}
	    		}
	    		printf("\n\n%s%d的十六进制 = %s\n\n\n",bs,begin,str);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	} 
	    	case 10:{//十六进制转化为二进制
	    		system("cls");
	    		printf("%s*************十六进制转化为二进制*************\n\n",bs);
	    		long long end;
	    		char begin[100];
	    		printf("\n\n%s请输入十六进制数:",bs);
	    		scanf("%s",begin); 
	    		string s(begin);
	    		end=SixteenChangeTwo(s);
	    		printf("\n\n%s%s的二进制 = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
				getchar();    
				getchar();
	    		system("cls");
	    		break; 
	    	} 
	    	case 11:{//十六进制转化为八进制}    
	    		system("cls");
	    		printf("%s*************十六进制转化为八进制*************\n\n",bs);
	    		long long end;
	    		char begin[100];
	    		printf("\n\n%s请输入十六进制数:",bs);
	    		scanf("%s",begin); 
	    		string s(begin);
	    		end=SixteenChangeEight(begin);;
	    		printf("\n\n%s%s的八进制 = %lld\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
	    		getchar();
	    		getchar();
	    		system("cls");
	    		break;
	    	} 
	    	case 12:{//十六进制转化为十进制
	    		system("cls");
	    		printf("%s*************十六进制转化为十进制*************\n\n",bs);
	    		int end;
	    		char begin[100];
	    		printf("\n\n%s请输入十六进制数:",bs);
	    		scanf("%s",begin); 
	    		string s(begin);
	    		end=SixteenChangeNine(s);
	    		printf("\n\n%s%s的十进制 = %d\n\n\n",bs,begin,end);
	    		printf("\n\n%s<回车返回菜单>",bs);
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
