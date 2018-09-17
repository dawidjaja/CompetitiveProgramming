var
	list:array[0..100000] of string;
	text:ansistring;
	i,n,y,cek,tes,lol:longint;
begin
	readln(text);
	for i:=1 to length(text) do
		begin
		list[i]:=copy(text,i,1);
		end;
	y:=1;
	tes:=0;
	for i:=1 to length(text) do
		begin
		if list[i]=' ' then
			begin
			cek:=0;
			lol:=1;
			for n:=y to i-1 do
				begin
				if list[n]=list[i-lol] then
					begin
					lol:=lol+1;
					end
				else
					begin
					cek:=1;
					break;
					end;
				end;
			if cek=0 then
				begin
				if tes=0 then
					begin
					for n:=y to i-1 do
						begin
						write(list[n]);
						end;
					tes:=1;
					end
				else
					begin
					write(' ');
					for n:=y to i-1 do
						begin
						write(list[n]);
						end;
					end;
				end;
			y:=i+1;
			end;
		end;
	lol:=0;
	cek:=0;
	for n:=y to length(text) do
		begin
		if list[n]=list[length(text)-lol] then
			begin
			lol:=lol+1;
			end
		else
			begin
			cek:=1;
			end;
		end;
		if cek=0 then
			begin
			if tes=1 then
				begin
				write(' ');
				for n:=y to length(text) do
					begin
					write(list[n]);
					end;
				end
			else
				begin
				for n:=y to length(text) do
					begin
					write(list[n]);
					end;
				end
			end;
	writeln;
end.