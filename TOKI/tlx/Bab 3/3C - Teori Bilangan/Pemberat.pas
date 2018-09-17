var
	list,dwa:array[0..10000] of int64;
	i,n:longint;
	sls,b,k:int64;
begin
	readln(b);
	readln(k);
	sls:=(k-b);
	i:=0;
	dwa[0]:=1;
	for n:=1 to 60 do
		begin
		dwa[n]:=dwa[n-1]*2;
		end;
	while sls<>1 do
		begin
		if sls mod 2=1 then
			begin
			sls:=sls div 2;
			list[i]:=1;
			i:=i+1;
			end;
		if sls mod 2=0 then
			begin
			sls:=sls div 2;
			list[i]:=0;
			i:=i+1;
			end;
		end;
	list[i]:=1;
	for n:=i downto 0 do
		begin
		if list[n]=1 then
			begin
			writeln(dwa[n]);
			end;
		if list[n]=0 then	
			begin
			end;
		end;
end.