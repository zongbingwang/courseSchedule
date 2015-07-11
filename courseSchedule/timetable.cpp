#include "stdafx.h"
#include "tools.h"
#include "timetable.h"

/*
Algorithm:
	//Need to write search methods according to some criteria for both teachers and Courses	
	Three Semesters. Each sem has three sections .
	Global: search for lab hours, allocate all of them.(Max of two sections in the lab)(Have to do fro all three sems before other subjects-> Randomize the sem chosen)		
	Lets go in order i.e 3,5,7 or 4,6,8	
	1. First fetch all courses pertaining to the current sem.
	2. Fetch corresponding teachers.
	3. Search the courses for a common course. If found, allocate required hours to it. (how?)
	4. Use the same algo as the one used for the python project . ALso include checks to the other semester's timetable to see that the teachers don't clash. Make sure the constraints are not violated. 
	5. May need to check previous hour because of constraint validation.(In case of no continuos hours)
*/


/*
one array for each section of a semester
	each array will have 6 arrays which contain pointers to integer pointers which point to values
	of courseid and the corresponding teacher who handles the course at that hour of the week
*/
//Ȩ��
const double Wa=0.8;  //��ʦ��ͻ
const double Wb=0.8;  //���ҳ�ͻ
const double Wc=0.2;  //����
const double Wd=0.1;  //����֮��������
const double We=0.05;  //���Ҳ�����

/*
void Timetable::encoding()
{
	
}

int Timetable::decoding(int i)
{
	int sum=0;
	for (int j=0;j<5;j++) sum+=V[i].G[j]<<j;
	return sum;
}*/


void Timetable::input_test()
{
	FILE* stream;
	freopen_s(&stream,"input.txt","r",stdin);
	freopen_s(&stream,"output.txt","w",stdout);

	int id;
	std::string name;

	int totPeople;
	int nS;

	//�༶nS�������ѧ��Ҫ�ϼ��ſ�
	std::cin>>C;
	std::string department;
	for (int c=0;c<C;c++)
	{
		std::cin>>id>>department>>name>>totPeople>>nS;

		vC.push_back(Class(id,department,name,totPeople));
		for (int s=0;s<nS;s++)
		{
			std::cin>>id;
			vC[c].insertSubjects(id);
		}
	}

	//ʱ��P ÿ���ܹ����ٿ�ʱP
	//name���ڼ���lesson�ڼ��ڿ�
	std::cin>>P;
	int lesson;
	for (int p=0;p<P;p++)
	{
		std::cin>>id>>name>>lesson;
		vP.push_back(Time(id,name,lesson));
	}

	//����R����Ŀ
	//d
	std::cin>>R;
	for (int r=0;r<R;r++)
	{
		std::cin>>id>>name>>totPeople;
		vR.push_back(ClassRoom(id,name,totPeople));
	}

	//S��������Ŀ
	//cID��classID��tID����teacherID
	std::cin>>S;
	int cID;
	int totlesson;
	int weeklesson;
	int tID;
	for (int s=0;s<S;s++)
	{
		std::cin>>id>>cID>>name>>totlesson>>weeklesson>>tID;
		vS.push_back(Subject(id,cID,name,totlesson,weeklesson,tID));
	}

	//��ʦ
	std::cin>>T;
	for (int t=0;t<T;t++)
	{
		std::cin>>id>>name>>nS;
		vT.push_back(Teacher(id,name));
		for (int s=0;s<nS;s++)
		{
			std::cin>>id;
			vT[t].insertSubjects(id);
		}
	}
}

void Timetable::input()
{

	int id;
	std::string name;
	std::string department;
	int totPeople;

	int C = 0 ;   //�༶����
	int P = 0;   //ʱ��
	int S = 0;   //����
	int R = 0;   //����
	int T = 0;   //��ʦ
	//int nS;
	//
	//�༶,nS�������ѧ��Ҫ�ϼ��ſ�
	//C�ǰ༶������
	CString cmdStr = _T("SELECT  * FROM class order by classID Desc");
	CDatabase db;
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"classID", varID);
		id = _ttoi(varID);
		CString varName;
		rs.GetFieldValue(L"className", varName);
		name = _ttoi(varName);
		CString varNum;
		rs.GetFieldValue(L"classNum", varNum);
		totPeople = _ttoi(varNum);
		CString varCollege;
		rs.GetFieldValue(L"college", varCollege);
		department = _ttoi(varCollege);
		vC.push_back(Class(id, department, name, totPeople));

		CRecordset rs2(&db);
		CString cmdStr2 = _T("SELECT  * FROM course order by courseID Desc");
		rs2.Open(CRecordset::forwardOnly, (L"%s", cmdStr2));

		while (!rs2.IsEOF()){
			int c = 0;
			CString subject_class_ID_str;
			int subject_class_ID;
			CString subject_ID_str;//CString��ʽ�Ŀγ�ID
			int subject_ID;			//Int�Ϳγ�ID

			rs2.GetFieldValue(L"classID", subject_class_ID_str);
			subject_class_ID = _ttoi(subject_class_ID_str);
			if (id == subject_class_ID){
				rs2.GetFieldValue(L"courseID", subject_ID_str);
				subject_ID = _ttoi(subject_ID_str);
				vC[c].insertSubjects(subject_ID);
				}
			c++;
			rs2.MoveNext();
			}
		rs2.Close();
		C++;
		rs.MoveNext();
		}
		rs.Close();
		db.Close();



	//ʱ��P �ܹ��м���
	//name�ܼ���lesson�ڼ��ڿ�
	int lesson;
	cmdStr = _T("SELECT  * FROM time order by timeID Desc");
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
		{
			CString varID;
			rs.GetFieldValue(L"timeID", varID);
			id = _ttoi(varID);
			CString varDay;
			rs.GetFieldValue(L"timeDay", varDay);
			name = _ttoi(varDay);
			CString varN;
			rs.GetFieldValue(L"N", varN);
			lesson = _ttoi(varN);
			vP.push_back(Time(id, name, lesson));
			rs.MoveNext();
			P++;
		}
	rs.Close();
	db.Close();


	//����R����Ŀ
	//d
	cmdStr = _T("SELECT  * FROM room order by roomID Desc");
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
//	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"roomID", varID);
		id = _ttoi(varID);
		CString varName;
		rs.GetFieldValue(L"roomName", varName);
		name = _ttoi(varName);
		CString varNum;
		rs.GetFieldValue(L"roomNum", varNum);
		totPeople = _ttoi(varNum);
		vR.push_back(ClassRoom(id, name, totPeople));
		rs.MoveNext();
		R++;
	}
	rs.Close();
	db.Close();


	//S�γ�����Ŀ
	//cID��classID��tID����teacherID
	int cID;
	int totlesson;
	int weeklesson;
	int tID;
	cmdStr = _T("SELECT  * FROM course order by courseID Desc");
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"courseID", varID);
		id = _ttoi(varID);
		CString varName;
		rs.GetFieldValue(L"courseName", varName);
		name = _ttoi(varName);
		CString varCID; //ClassID
		rs.GetFieldValue(L"classID", varCID);
		cID = _ttoi(varCID);
		CString varTotal;
		rs.GetFieldValue(L"totalTime", varTotal);
		totlesson = _ttoi(varTotal);
		CString varWeek;
		rs.GetFieldValue(L"weekTime", varWeek);
		weeklesson = _ttoi(varWeek);
		CString varTID;//TeacherID
		rs.GetFieldValue(L"teacherID", varTID);
		tID = _ttoi(varTID);
		vS.push_back(Subject(id, cID, name, totlesson, weeklesson, tID));
		rs.MoveNext();
		S++;
	}
	rs.Close();
	db.Close();

	//��ʦT
	cmdStr = _T("SELECT  * FROM teacher order by teacherID Desc");
	db.Open(NULL, FALSE, FALSE, L"ODBC;DSN=TEST2;UID=root;PWD=1234");
	rs.Open(CRecordset::forwardOnly, (L"%s", cmdStr));
	while (!rs.IsEOF())
	{
		CString varID;
		rs.GetFieldValue(L"teacherID", varID);
		id = _ttoi(varID);
		CString varName;
		rs.GetFieldValue(L"teacherName", varName);
		name = _ttoi(varName);
		vT.push_back(Teacher(id, name));

		CRecordset rs2(&db);
		CString cmdStr2 = _T("SELECT  * FROM course order by courseID Desc");
		rs2.Open(CRecordset::forwardOnly, (L"%s", cmdStr2));
		while (!rs2.IsEOF()){
			int t = 0;
			CString subject_teacher_ID_str;
			int subject_teacher_ID;
			CString subject_ID_str;//CString��ʽ�Ŀγ�ID
			int subject_ID;			//Int�Ϳγ�ID

			rs2.GetFieldValue(L"teacherID", subject_teacher_ID_str);
			subject_teacher_ID = _ttoi(subject_teacher_ID_str);
			if (id == subject_teacher_ID)//��ʦID�����ſεĽ�ʦID������Ͱ����ſε�ID��¼��ȥ
			{
				rs2.GetFieldValue(L"courseID", subject_ID_str);
				subject_ID = _ttoi(subject_ID_str);
				vT[t].insertSubjects(subject_ID);
			}
			t++;
			rs2.MoveNext();
		}
		rs2.Close();
		rs.MoveNext();
		T++;

	}
	rs.Close();
	db.Close();


}

double Timetable::H(int p)//������ð���˳�򣬾�������������
{
	//std::cout<<1.0/((4-p%4)*20.0)<<std::endl;
	return 1.0/((4-p%4)*20.0);     //ʱ����Ӧ�Ⱥ���

}

void Timetable::init()//��ʼ����ȺV����ά����ijk�༶-ʱ��-0����1����
{
	srand( (unsigned)time(NULL));
	//���ԭ�ȴ��ڵ�����
	vC.clear();
	vS.clear();
	vR.clear();
	vT.clear();
	vP.clear();

	//�����ʼ����
	input_test();

	//��ʼ������
	for (int i=0;i<M;i++)
		for (int c=0;c<C;c++)
			for (int p=0;p<P;p++) V[i].G[c][p][0]=-1,V[i].G[c][p][1]=-1;

	//��ʼ��M������
	//srand( (unsigned)time(NULL));
	for (int i=0;i<M;i++)
	{
		for (int p=0;p<P;p++)
			for (int r=0;r<R;r++) USE[p][r]=-1;

		for (int c=0;c<C;c++)
			for (int s=0;s<vC[c].S;s++)
			{
				int week_lesson=vS[vC[c].Subjects[s]].week_lesson;
				while (week_lesson--)
				{
					//Ϊÿһ�ÿ�ѡ��ʱ��
					int tID=randab(0,P-1);
					int l=tID,r=tID;
					while (l>=0 && r<P && V[i].G[c][l][0]!=-1 && V[i].G[c][r][0]!=-1)
					{
						l--;
						r++;
					}
					if (l>=0&&V[i].G[c][l][0]==-1) tID=l;
					if (r<P &&V[i].G[c][r][0]==-1) tID=r;
					V[i].G[c][tID][0]=vC[c].Subjects[s];//V�������ļ��ϣ��༶�ļ���

					//Ϊÿһ�ÿ�ѡ�����
					int rID=randab(0,R-1);
					l=rID,r=rID;
					while (l>=0 && r<R && USE[tID][l]!=-1 && USE[tID][r]!=-1)
					{
						l--;
						r++;
					}
					if (l>=0&&USE[tID][l]==-1) rID=l;
					if (r<P &&USE[tID][r]==-1) rID=r;
					V[i].G[c][tID][1]=rID;
				}
			}
	}
	start_id=0;
}

void Timetable::eliminate(int start)
{
	//������ͻ
	for (int i=start;i<start+M;i++)
	{
		//��ʦ��ͻ
		for (int p=0;p<P;p++)
			for (int c1=1;c1<C;c1++)
				if (V[i].G[c1][p][0]!=-1)
				for (int c2=c1-1;c2>=0;c2--)
					if (V[i].G[c2][p][0]!=-1 && vS[V[i].G[c1][p][0]].teacher_id==vS[V[i].G[c2][p][0]].teacher_id)
					{
						int tID=randab(0,P-1);
						/*
						while (!(V[i].G[c1][p][0]!=V[i].G[c1][tID][0] && V[i].G[c1][tID][0]!=-1))
						{
							tID=randab(0,P-1);
						}
						std::swap(V[i].G[c1][p][0], V[i].G[c1][tID][0]);*/
						while (!(V[i].G[c1][tID][0]!=-1 && vS[V[i].G[c1][p][0]].teacher_id!=vS[V[i].G[c1][tID][0]].teacher_id))
						{
							tID=randab(0,P-1);
						}
						std::swap(V[i].G[c1][p], V[i].G[c1][tID]);
					}

		//���ҳ�ͻ
		for (int p=0;p<P;p++)
			for (int c1=1;c1<C;c1++)
				if (V[i].G[c1][p][1]!=-1)
				for (int c2=c1-1;c2>=0;c2--)
					if (V[i].G[c1][p][1]==V[i].G[c2][p][1] && V[i].G[c1][p][1]!=-1)
					{
						int tID=randab(0,P-1);
						/*
						while (!(V[i].G[c1][p][1]!=V[i].G[c1][tID][1] && V[i].G[c1][tID][1]!=-1))
						{
							tID=randab(0,P-1);
						}
						std::swap(V[i].G[c1][p][1], V[i].G[c1][tID][1]);*/
						while (!(V[i].G[c1][p][1]!=V[i].G[c1][tID][1]))
						{
							tID=randab(0,P-1);
						}
						std::swap(V[i].G[c1][p], V[i].G[c1][tID]);
					}
	}

}

void Timetable::evalueFitness(int start)
{
	//������Ӧ�Ⱥ���
	sumfitness=0;

	double f;
	for (int i=start;i<start+M;i++)
	{
		int a=0, b=0, cc=0, d=0, e=0;
		f=0;
		for (int p=0;p<P;p++)
		{
			for (int c1=0;c1<C;c1++)
				if (V[i].G[c1][p][0]!=-1 && V[i].G[c1][p][1]!=-1)
				for (int c2=c1+1;c2<C;c2++)
				{
					if (c1!=c2 && V[i].G[c2][p][0]!=-1 && vS[V[i].G[c1][p][0]].teacher_id==vS[V[i].G[c2][p][0]].teacher_id ) {f+=Wa;a++;}  //��ʦ��ͻ
					
					if (c1!=c2&&V[i].G[c1][p][1]==V[i].G[c2][p][1] && V[i].G[c1][p][1]!=-1) {f+=Wb;b++;}  //���ҳ�ͻ
				}
			for (int c=0;c<C;c++)
			{
				if (p>0 && V[i].G[c][p-1][0]==V[i].G[c][p][0] && V[i].G[c][p][0]!=-1){f+=Wc;cc++;}        //���ų�ͻ
				if (p>0 && p%2==0 && V[i].G[c][p-1][1]!=V[i].G[c][p][1] && V[i].G[c][p-1][1]!=-1 && V[i].G[c][p][1]!=-1) {f+=We*abs( V[i].G[c][p-1][1]-V[i].G[c][p][1]);e++;}        //���Ҳ�����
				if (V[i].G[c][p][0]!=-1) f+=H(p);                                                   //ʱ����Ӧ�Ⱥ���
			}
		}
		for (int c=0;c<C;c++)
			for (int p1=0;p1<P;p1++)
				if (V[i].G[c][p1][0]!=-1)
				for (int p2=p1+1;p2<min(P,p1+8);p2++) if (p2<P && V[i].G[c][p1][0]==V[i].G[c][p2][0] && V[i].G[c][p1][0]!=-1)
				{f+=Wd;d++;}                                                                          //����֮�������ο�����
				//printf("%d:%d %d %d %d %d\n",i,a,b,cc,d,e);
		V[i].fitness=1/(f+1);
		sumfitness+=V[i].fitness;
	}

}

void Timetable::choose_pi(int start)
{
	//srand((int)time(0));
	//srand( (unsigned)time(NULL));
	int next=getNew(start);

	for (int i=0;i<(int)(M*(1-pr)+0.1);i++)
	{
		double value=randab(0.000001, 0.999999);
		//printf("%f\n",value);
		double temPi=0;
		for (int j=start;j<start+M;j++)
		{
			if (temPi<value && value<=temPi+V[j].fitness/sumfitness) { /*printf("%d %f %f\n",j,value, temPi);*/V[next++]=V[j];break;}
			temPi+=(V[j].fitness/sumfitness);
		}
		//printf("%lf   %lf\n",temPi,sumfitness);
	}

	//start_id=next-(int)M*(1-pr);
}

void Timetable::crossover(int start)
{
	//srand(time(0));
	int next=getNew(start)+(int)(M*(1-pr)+0.1);

	for (int i=0;i<((int)(M*pr+0.1))/2;i++)
	{
		int father;
		int mother;

		//�ֶ����㷨ѡ���׺�ĸ��
		while (true)
		{
			double value1=randab(0.000001, 0.999999),value2=randab(0.000001, 0.999999);
		    double temPi=0;
		    for (int j=start;j<start+M;j++)
		    {
			   if (temPi<value1 && value1<=temPi+V[j].fitness/sumfitness) {father=j;}
			   if (temPi<value2 && value2<=temPi+V[j].fitness/sumfitness) {mother=j;}
			   temPi+=(V[j].fitness/sumfitness);
		    }
			if (father!=mother) break;
		}

		int middle=randab(0,C-1);          //�����������ѡ��һ��Ⱦɫ�壨�༶������
		V[next]=V[father];
		V[next+1]=V[mother];
		std::swap(V[next].G[middle], V[next+1].G[middle]);
		next+=2;
	}
	start_id=next-M;
}

void Timetable::mutation(int start)
{
	//srand(time(0));
	int next=getNew(start);

	for (int i=0;i<M;i++)
	{
		V[next]=V[start];

		double mutate=randab(0.0,1.0);
		if (mutate>pm)
		{
			next++;
			start++;
			continue;
		}

		int id=randab(0,C-1);                     //�������һ���༶���ÿε�ʱ�� ���ÿεĽ���
		int pID1=randab(0,P-1);
		int pID2=randab(0,P-1);
		while (!(pID1!=pID2 && V[next].G[id][pID1][0]!=-1 && V[next].G[id][pID2][0]!=-1))
		//while (!(pID1!=pID2))
		{
			pID1=randab(0,P-1);
		    pID2=randab(0,P-1);
		}
		std::swap(V[next].G[id][pID1], V[next].G[id][pID2]);

		/*
		int rID1=randab(0,P-1);
		int rID2=randab(0,P-1);
		while (!(rID1!=rID2 && V[next].G[id][rID1][1]!=-1 && V[next].G[id][rID2][1]!=-1))
		{
			rID1=randab(0,P-1);
		    rID2=randab(0,P-1);
		}
		std::swap(V[next].G[id][rID1][1], V[next].G[id][rID2][1]);*/

		next++;
		start++;
	}

	start_id=next-M;
}

void Timetable::GA()
{
	//printResult();
	evalueFitness(start_id);//������Ӧֵ
	eliminate(start_id);//��ͻ��⣬������������༶�γ̳�ͻ�ˣ��ڰ༶�ڲ��γ�ѡ�񽻻���ÿһ������һ�Ρ�
	choose_pi(start_id);//��Ȼѡ��
	crossover(start_id);//����
	mutation(start_id);//����
	//printf("%lf\n",sumfitness);
}

void Timetable::printResult()
{
	FILE* stream;
	//freopen_s(&stream,"input.txt","r",stdin);
	freopen_s(&stream,"output.txt","w",stdout);

	int start=start_id;
	evalueFitness(start_id);
	int people;
	double max=0;

	for (int i=start;i<start+M;i++)
		if (V[i].fitness>max) 
		{
			max=V[i].fitness;
			people=i;
		}
	//	std::cout<<people<<" "<<max<<std::endl;
	for (int c=0;c<C;c++)
	{
		std::cout<<"�༶"<<c<<":"<<std::endl;
		for (int p=0;p<P;p++)
		{
			if (p%4==0) std::cout<<vP[p].name<<":"<<std::endl;
			if (V[people].G[c][p][0]!=-1) std::cout<<vP[p].lesson<<":	����:"<<vS[V[people].G[c][p][0]].name<<"	��ʦ:"<<vT[vS[V[people].G[c][p][0]].teacher_id].name<<"	����:"<<vR[V[people].G[c][p][1]].name<<std::endl;
		}
		std::cout<<"�༶�ָ���----------------------�༶�ָ���"<<std::endl;
	}
}