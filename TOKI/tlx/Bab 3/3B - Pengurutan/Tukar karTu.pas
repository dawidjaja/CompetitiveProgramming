var
	list:array[1..1000] of longint;
	a,i,temp,tls,sm:longint;
begin
	tls:=0;
	sm:=0;
	readln(a);
	for i:=1 to a do
		begin
		readln(list[i]);
		end;
	while sm<>a-1 do
		begin
		sm:=0;
		for i:=1 to a-1 do
			begin
			if list[i]>list[i+1] then
				begin
				temp:=list[i];
				list[i]:=list[i+1];
				list[i+1]:=temp;
				tls:=tls+1;
				end
			else
				begin
				sm:=sm+1;
				end;
			end;
		end;
	writeln(tls);
end.