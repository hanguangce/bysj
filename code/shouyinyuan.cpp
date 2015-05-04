//// new  
init(){
Nnum=0;
}


OnOk(){

add all info;

}



int OnAdd{
   if(Nnum>10||Nnum<0)
   {	
	messagexBox("can not insert");
	return 0;
   }
   DShowProd showprod;
   showprod.D***();
 jyjlset[Nnum]=howprod.ic_value; 

	Nnum++;
	更新都买衣服报表；
}

DShowProd{
   init（）{
    
    查询 显示  ic  name   // select *  from  product rep where rep.ct >0 
 
   默认值是index=0；
   
   
   }


	 onok(){
 		ic_value = get_ic ();
   

 	}

查询 最大值交易流水号
select * from jyjl where  jylsh in （select max（jylsh） from jyjl）
}
