var
	list:array[-8000..8000] of longint;
	a,msk,m,n,i,x:longint;
	klr,hsl:real;
begin
	readln(msk);
	n:=0;
	m:=8001;
	for i:=-8000 to 8000 do
		begin
		list[i]:=0;
		end;
	for i:=1 to msk do
		begin
		read(a);
		list[a]:=list[a]+1;
		end;
	if (msk mod 2=1) then
		begin
		klr:=(msk+1)/2;
		for i:=-8000 to 8000 do 
			begin
			if klr>0 then 
				begin
				klr:=klr-list[i];
				if klr<1 then
					begin
					n:=i;
					end;
				end;
			end;
		hsl:=n;
		writeln(hsl:0:2);
		end;
	if (msk mod 2=0) then
		begin
		klr:=msk/2;
		for i:=-8000 to 8000 do
			begin
			if klr>0 then
				begin
				klr:=klr-list[i];
					if klr<1 then
					begin
					n:=i;
					if klr<0 then
						begin
						m:=n;
						end;
					if klr=0 then
						begin
						for x:=i+1 to 8000 do
							begin
								if klr<>klr+-list[x] then
								begin
									if x<m then
									begin
									m:=x;
									end;
								end;
							end;
						end;
					end;
				end;
			end;
		hsl:=((n+m)/2);
		writeln(hsl:0:2);
		end;
end.