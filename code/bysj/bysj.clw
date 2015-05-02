; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=pro_rep_set
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "bysj.h"

ClassCount=17
Class1=CBysjApp
Class2=CBysjDlg
Class3=CAboutDlg

ResourceCount=13
Resource1=IDR_MENU1
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_ShouYinYuan
Resource5=IDD_DIALOG5
Resource6=IDD_DianZhang
Resource7=IDD_JYJL
Resource8=IDD_KuGuan
Resource9=IDD_BYSJ_DIALOG
Resource10=IDD_DIALOG6
Class4=CDianZhang
Class5=KuGuan
Resource11=IDD_KGCX
Class6=Cdb
Class7=CKuguanSet
Class8=res
Class9=CDiolag
Class10=productset
Class11=repset
Class12=priceset
Class13=empty
Class14=xsjlset
Resource12=IDR_MENU2
Class15=databaseset
Class16=Dkgcx
Class17=pro_rep_set
Resource13=IDR_TOOLBAR1

[CLS:CBysjApp]
Type=0
HeaderFile=bysj.h
ImplementationFile=bysj.cpp
Filter=N
LastObject=CBysjApp

[CLS:CBysjDlg]
Type=0
HeaderFile=bysjDlg.h
ImplementationFile=bysjDlg.cpp
Filter=D
LastObject=IDC_COMBO1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=bysjDlg.h
ImplementationFile=bysjDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BYSJ_DIALOG]
Type=1
Class=CBysjDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO1,combobox,1344340226

[DLG:IDD_DIALOG5]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG6]
Type=1
Class=Cdb
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SQL,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_yginfo
Command2=ID_hwidfo
Command3=ID_kcinfo
CommandCount=3

[TB:IDR_TOOLBAR1]
Type=1
Class=?
CommandCount=0

[CLS:CDianZhang]
Type=0
HeaderFile=DianZhang.h
ImplementationFile=DianZhang.cpp
BaseClass=CDialog
Filter=D
LastObject=CDianZhang

[DLG:IDD_DianZhang]
Type=1
Class=CDianZhang
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425

[CLS:KuGuan]
Type=0
HeaderFile=KuGuan.h
ImplementationFile=KuGuan.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

[DLG:IDD_KuGuan]
Type=1
Class=KuGuan
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425

[DLG:IDD_ShouYinYuan]
Type=1
Class=?
ControlCount=13
Control1=ID_TIJIAO,button,1342242817
Control2=ID_RESET,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_COMBO1,combobox,1344340226
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,button,1342177287

[CLS:Cdb]
Type=0
HeaderFile=db.h
ImplementationFile=db.cpp
BaseClass=CDialog
Filter=D
LastObject=Cdb

[CLS:CKuguanSet]
Type=0
HeaderFile=KuguanSet.h
ImplementationFile=KuguanSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CKuguanSet

[DB:CKuguanSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[id], 4, 4
Column2=[name], 1, 50
Column3=[type], 1, 30
Column4=[subtype], 1, 30
Column5=[pinpai], 12, 50

[CLS:res]
Type=0
HeaderFile=res.h
ImplementationFile=res.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=res

[DB:res]
DB=1
DBType=ODBC
ColumnCount=0

[CLS:CDiolag]
Type=0
HeaderFile=Diolag.h
ImplementationFile=Diolag.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CDiolag

[DB:CDiolag]
DB=1
DBType=ODBC
ColumnCount=13
Column1=[id], 4, 4
Column2=[ic], 4, 4
Column3=[oc], 4, 4
Column4=[pp], 4, 4
Column5=[pm], 12, 510
Column6=[kh], 12, 510
Column7=[ty], 12, 510
Column8=[jx], 12, 510
Column9=[pn0], 12, 510
Column10=[p0], 12, 510
Column11=[prod], 12, 510
Column12=[pn1], 12, 510
Column13=[ph1], 12, 510

[CLS:productset]
Type=0
HeaderFile=productset.h
ImplementationFile=productset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:productset]
DB=1
DBType=ODBC
ColumnCount=17
Column1=[price].[ic], 4, 4
Column2=[jp], 4, 4
Column3=[bp], 4, 4
Column4=[lr], 4, 4
Column5=[id], 4, 4
Column6=[product].[ic], 4, 4
Column7=[oc], 4, 4
Column8=[pp], 4, 4
Column9=[pm], 12, 510
Column10=[kh], 12, 510
Column11=[ty], 12, 510
Column12=[jx], 12, 510
Column13=[pn0], 12, 510
Column14=[p0], 12, 510
Column15=[prod], 12, 510
Column16=[pn1], 12, 510
Column17=[ph1], 12, 510

[CLS:repset]
Type=0
HeaderFile=repset.h
ImplementationFile=repset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:repset]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[ic], 4, 4
Column2=[ct], 4, 4
Column3=[ct0], 4, 4
Column4=[mg], 12, 510

[CLS:priceset]
Type=0
HeaderFile=priceset.h
ImplementationFile=priceset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:priceset]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[ic], 4, 4
Column2=[jp], 4, 4
Column3=[bp], 4, 4
Column4=[lr], 4, 4

[CLS:empty]
Type=0
HeaderFile=empty.h
ImplementationFile=empty.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:empty]
DB=1
DBType=ODBC
ColumnCount=10
Column1=[eid], 4, 4
Column2=[ename], 12, 510
Column3=[esex], 12, 510
Column4=[eage], 12, 510
Column5=[emon], 4, 4
Column6=[eages], 12, 510
Column7=[ecot1], 12, 510
Column8=[ecot2], 12, 510
Column9=[ecp], 12, 510
Column10=[ecpn], 12, 510

[CLS:xsjlset]
Type=0
HeaderFile=xsjlset.h
ImplementationFile=xsjlset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:xsjlset]
DB=1
DBType=ODBC
ColumnCount=17
Column1=[jylsh], 4, 4
Column2=[syy], 4, 4
Column3=[xsyg], 4, 4
Column4=[jysj], 11, 16
Column5=[jysl], 4, 4
Column6=[jyje], 4, 4
Column7=[lr], 4, 4
Column8=[p1], 12, 510
Column9=[p2], 12, 510
Column10=[p3], 12, 510
Column11=[p4], 12, 510
Column12=[p5], 12, 510
Column13=[p6], 12, 510
Column14=[p7], 12, 510
Column15=[p8], 12, 510
Column16=[p9], 12, 510
Column17=[p10], 12, 510

[MNU:IDR_MENU2]
Type=1
Class=?
Command1=ID_KUGUAN0
Command2=ID_KUGUAN1
Command3=ID_KUGUAN2
Command4=ID_KUGUAN3
CommandCount=4

[CLS:databaseset]
Type=0
HeaderFile=databaseset.h
ImplementationFile=databaseset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=databaseset

[DB:databaseset]
DB=1
DBType=ODBC
ColumnCount=48
Column1=[eid], 4, 4
Column2=[ename], 12, 510
Column3=[esex], 12, 510
Column4=[eage], 12, 510
Column5=[emon], 4, 4
Column6=[eages], 12, 510
Column7=[ecot1], 12, 510
Column8=[ecot2], 12, 510
Column9=[ecp], 12, 510
Column10=[ecpn], 12, 510
Column11=[price].[ic], 4, 4
Column12=[jp], 4, 4
Column13=[bp], 4, 4
Column14=[price].[lr], 4, 4
Column15=[id], 4, 4
Column16=[product].[ic], 4, 4
Column17=[oc], 4, 4
Column18=[pp], 4, 4
Column19=[pm], 12, 510
Column20=[kh], 12, 510
Column21=[ty], 12, 510
Column22=[jx], 12, 510
Column23=[pn0], 12, 510
Column24=[p0], 12, 510
Column25=[prod], 12, 510
Column26=[pn1], 12, 510
Column27=[ph1], 12, 510
Column28=[rep].[ic], 4, 4
Column29=[ct], 4, 4
Column30=[ct0], 4, 4
Column31=[mg], 12, 510
Column32=[jylsh], 4, 4
Column33=[syy], 4, 4
Column34=[xsyg], 4, 4
Column35=[jysj], 11, 16
Column36=[jysl], 4, 4
Column37=[jyje], 4, 4
Column38=[xsjl].[lr], 4, 4
Column39=[p1], 12, 510
Column40=[p2], 12, 510
Column41=[p3], 12, 510
Column42=[p4], 12, 510
Column43=[p5], 12, 510
Column44=[p6], 12, 510
Column45=[p7], 12, 510
Column46=[p8], 12, 510
Column47=[p9], 12, 510
Column48=[p10], 12, 510

[DLG:IDD_JYJL]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344340226

[DLG:IDD_KGCX]
Type=1
Class=Dkgcx
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_KGCX_E0,edit,1350631552
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_BUTTON2,button,1342242816
Control6=IDC_BUTTON3,button,1342242816
Control7=IDC_BUTTON4,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_KGCX_E1,edit,1350631552
Control13=IDC_KGCX_E3,edit,1350631552
Control14=IDC_KGCX_E2,edit,1350631552

[CLS:Dkgcx]
Type=0
HeaderFile=Dkgcx.h
ImplementationFile=Dkgcx.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_kcinfo

[CLS:pro_rep_set]
Type=0
HeaderFile=pro_rep_set.h
ImplementationFile=pro_rep_set.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=pro_rep_set

[DB:pro_rep_set]
DB=1
DBType=ODBC
ColumnCount=17
Column1=[id], 4, 4
Column2=[product].[ic], 4, 4
Column3=[oc], 4, 4
Column4=[pp], 4, 4
Column5=[pm], 12, 510
Column6=[kh], 12, 510
Column7=[ty], 12, 510
Column8=[jx], 12, 510
Column9=[pn0], 12, 510
Column10=[p0], 12, 510
Column11=[prod], 12, 510
Column12=[pn1], 12, 510
Column13=[ph1], 12, 510
Column14=[rep].[ic], 4, 4
Column15=[ct], 4, 4
Column16=[ct0], 4, 4
Column17=[mg], 12, 510

