var
	a,b,n,i,j,angka:longint;
	brs,char:string;
	list:array[0..100000,0..100000] of longint;
	cost,cek,jmlh:array[0..10000] of longint;
begin
	readln(a,b,n);
	for i:=1 to n do
		begin
		readln(cost[i],jmlh[i]);
		for j:=1 to jmlh[i] do 
			begin
			read(brs);
			char:=val(copy(brs,(2*j-1),1),angka);
			list[i,j]:=char;
			end;
		end;
end.