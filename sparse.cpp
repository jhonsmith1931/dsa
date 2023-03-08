#include<iostream>
using namespace std;
class Matrix
{
	public : int m[20][20],i,j,r,c,t=0,a,trip[10][3];
	void read()
	{
		cout<<"Enter the no. of Rows : ";
		cin>>r;
		
		cout<<"Enter the no. of Column : ";
		cin>>c;
		
		cout<<"Enter the No.of Elements\n";
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>m[i][j];
				if(m[i][j])
				{
					t++;
					trip[t][0]=i+1;
					trip[t][1]=j+1;
					trip[t][2]=m[i][j];
				}
			}
		}
		trip[0][0]=r;
		trip[0][1]=c;
		trip[0][2]=t;
	}
	void disp_Mat()
	{
		cout<<"The Matrix is : \n";
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cout<<" "<<m[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	void disp_Trip()
	{
		cout<<"Triplet is : \n";
		for(i=0;i<=t;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<" "<<trip[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	void transpose()
	{
		int trans[10][5];
        trans[0][0]=trip[0][1];
        trans[0][1]=trip[0][0];
        trans[0][2]=trip[0][2];
        int q=1;
        for(i=0;i<=c;i++)
        {
           for(int p=1;p<=t;p++)
           {
            if(trip[p][1]==i)
            {
            	trans[q][0]=trip[p][1];
                trans[q][1]=trip[p][0];
                trans[q][2]=trip[p][2];
                q++;
            }
          }
       }
	cout<<"Transpose\n";
	for(i=0;i<=t;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<" "<<trip[i][j]<<" ";
			}
			cout<<"\n";
		}
   }
};
int main()
{
Matrix m;
  m.read();
  m.disp_Mat();
  m.disp_Trip();
  m.transpose();
  return 0;
	
}
