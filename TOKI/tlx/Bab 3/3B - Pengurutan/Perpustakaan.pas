var
	list:array[1..2500] of longint;
	a,msk,i,temp,hsl,n,x:longint;
begin
	readln(msk);
	hsl:=0;
	for i:=1 to msk do
		begin
		readln(list[i]);
		end;
	for i:=1 to msk do
		begin
		a:=0;
		temp:=list[i];		
		for n:=i+1 to msk do
			begin
			if list[n]<temp then
				begin
				temp:=list[n];
				a:=1;
				x:=n;
				end;
			end;
		if a=1 then
			begin
			list[x]:=list[i];
			list[i]:=temp;
			hsl:=hsl+1;
			end;
		end;
	writeln(hsl);
end.