; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiolag
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "bysj.h"

ClassCount=9
Class1=CBysjApp
Class2=CBysjDlg
Class3=CAboutDlg

ResourceCount=12
Resource1=IDR_MENU1
Resource2=IDR_MAINFRAME
Resource3=IDD_DianZhang
Resource4=IDD_ABOUTBOX
Resource5=IDD_KuGuan
Resource6=IDD_DIALOG6
Resource7=IDD_ShouYinYuan
Resource8=IDD_DIALOG4
Resource9=IDD_DIALOG5
Resource10=IDD_BYSJ_DIALOG
Class4=CDianZhang
Class5=KuGuan
Resource11=IDD_DIALOG1
Class6=Cdb
Class7=CKuguanSet
Class8=res
Class9=CDiolag
Resource12=IDR_TOOLBAR1

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

[DLG:IDD_DIALOG4]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

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
LastObject=KuGuan
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

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344340226

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

