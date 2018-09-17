var
	list:array[1..100] of longint;
	a,b,c,ma,ka,mb,kb,mc,kc,i,temp:longint;
begin
	readln(a,b,c);
	readln(ma,ka);
	readln(mb,kb);
	readln(mc,kc);
	temp:=0;
	for i:=1 to 100 do
		begin
			list[i]:=0;
		end;
	for i:=ma to ka-1 do 
		begin
		list[i]:=list[i]+1;
		end;
	for i:=mb to kb-1 do 
		begin
		list[i]:=list[i]+1;
		end;
	for i:=mc to kc-1 do 
		begin
		list[i]:=list[i]+1;
		end;
	for i:=1 to 100 do
		begin
		if list[i]=0 then
			begin
			end;
		if list[i]=1 then
			begin
			temp:=temp+a;
			end;
		if list[i]=2 then
			begin
			temp:=temp+b+b;
			end;
		if list[i]=3 then
			begin
			temp:=temp+c+c+c;
			end;
		end;
	writeln(temp);
end.