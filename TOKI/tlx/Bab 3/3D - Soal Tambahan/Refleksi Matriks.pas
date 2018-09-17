var
	ma,mb:array[1..100,1..100] of longint;
	msk,cek,x,y:longint;
begin
	readln(msk,msk);
	for y:=1 to msk do
		begin
		for x:=1 to msk do
			begin
			read(ma[y,x]);
			end;
		end;
	readln(msk,msk);
	for y:=1 to msk do
		begin
		for x:=1 to msk do
			begin
			read(mb[y,x]);
			end;
		end;
	cek:=1;
	for y:=1 to msk do
		begin
		for x:=1 to msk do
			begin
			if ma[y,x]=mb[y,x] then
				begin
				end
			else
				begin
				cek:=0;
				end;
			end;
		end;
	if cek=1 then
		begin
		writeln('identik');
		exit;
		end;
	cek:=2;
	for y:=1 to msk do
		begin
		for x:=1 to msk do
			begin
			if ma[y,x]=mb[y,(msk+1-x)] then
				begin
				end
			else
				begin
				cek:=0;
				end;
			end;
		end;
	if cek=2 then
		begin
		writeln('vertikal');
		exit;
		end;
	cek:=3;
	for y:=1 to msk do
		begin
		for x:=1 to msk do
			begin
			if ma[y,x]=mb[msk+1-y,x] then
				begin
				end
			else
				begin
				cek:=0;
				end;
			end;
		end;
	if cek=3 then
		begin
		writeln('horisontal');
		exit;
		end;
	cek:=4;
	for y:=1 to msk do
		begin
		for x:=1 to msk do
			begin
			if ma[y,x]=mb[x,y] then
				begin
				end
			else
				begin
				cek:=0;
				end;
			end;
		end;
	if cek=4 then
		begin
		writeln('diagonal kanan bawah');
		exit;
		end;
	cek:=5;
	for y:=1 to msk do
		begin
		for x:=1 to msk do
			begin
			if ma[y,x]=mb[msk+1-x,msk+1-y] then
				begin
				end
			else
				begin
				cek:=0;
				end;
			end;
		end;
	if cek=5 then
		begin
		writeln('diagonal kiri bawah');
		exit;
		end;
	if cek=0 then
		begin
		writeln('tidak identik');
		end;
end.