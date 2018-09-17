var
	a,b,n,hsl,i,j:longint;
	list:array[0..100000,0..100000] of longint;
	cost,cek,jmlh:array[0..10000] of longint;
begin
	readln(a,b,n);
	for i:=1 to n do
		begin
		read(cost[i],jmlh[i]);
		for j:=1 to jmlh[i] do
			begin
			read(list[i,j]);
			end;
		end;
	for i:=1 to n do
		begin
		cek[i]:=0;
		for j:=1 to jmlh[i] do
			begin
			if list[i,j]=a then
				begin
				cek[1]:=1;
				end;
			if cek[1]=1 then
				begin
				if list[i,j]=b then
					begin
					cek[1]:=2;
					end;
				end;
			end;
		end;
	hsl:=cost[1];
	for i:=1 to n do
		begin
		if cek[i]=2 then
			begin
			if cost[i]<hsl then
				begin
				hsl:=cost[i];
				end;
			end;
		end;
	writeln(hsl);
end.