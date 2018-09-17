var
	list:array[0..1000000] of longint;
	i,n:longint;
	a,b,hsl,temp:int64;
begin
	readln(a,b);
	for i:=1 to a do
		begin
		readln(list[i]);
		end;
	hsl:=0;
	if (a mod b=0) then
		begin
		for n:=0 to ((a div b)-1) do
			begin
			temp:=0;
				for i:=1 to b do 
				begin
					if temp<list[(i+(n*b))] then
					begin
						temp:=list[(i+(n*b))];
					end;
				end;
				hsl:=hsl+temp;
			end;
		hsl:=hsl+1+(a div b);
		end;
	if (a mod b<>0) then
		begin
			for n:=0 to (a div b) do
			begin
			temp:=0;
				for i:=1 to b do 
				begin
					if temp<list[i+(n*b)] then
					begin
						temp:=list[i+(n*b)];
					end;
				end;
				hsl:=hsl+temp;
			end;
		hsl:=hsl+2+(a div b);
		end;
	writeln(hsl);
end.