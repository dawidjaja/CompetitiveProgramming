var
	list,scd,dat:array[0..600000] of longint;
	a,i,n,temp,smntr,x,z:longint;
begin
	readln(list[1]);
	i:=2;
	while not eof do
		begin
		readln(a);
			if a=list[i-1] then
			begin
			end
		else
			begin
			list[i]:=a;
			i:=i+1;
			end;
		end;
	temp:=2;
	scd[1]:=list[1];
	for n:=2 to i-1 do
		begin
		if ((list[n]>list[n+1]) and (list[n]>list[n-1])) then
			begin
			scd[temp]:=list[n];
			temp:=temp+1;
			end;
		if ((list[n]<list[n+1]) and (list[n]<list[n-1])) then
			begin
			scd[temp]:=list[n];
			temp:=temp+1;
			end;
		end;
	scd[temp]:=a;
	for x:=1 to temp-1 do	
		begin
		dat[x]:=abs(scd[x+1]-scd[x]);
		end;
	smntr:=0;
	for z:=1 to temp do
		begin
		if dat[z]>smntr then
			begin
			smntr:=dat[z];
			end;
		end;
	writeln(smntr);
end.