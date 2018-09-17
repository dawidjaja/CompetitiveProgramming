var
	msk,i,j,cek:longint;
	ma,mb:array[0..100,0..100] of longint;
begin
	readln(msk,msk);
	for i:=1 to msk do
		begin
		for j:=1 to msk do	
			begin
			read(ma[i,j]);
			end;
		end;
	readln(msk,msk);
	for i:=1 to msk do
		begin
		for j:=1 to msk do	
			begin
			read(mb[i,j]);
			end;
		end;
	cek:=0;
	for i:=1 to msk do
		begin
		for j:=1 to msk do
			begin
			if ma[i,j]<>mb[i,j] then
				begin
				cek:=1;
				break;
				end;
			end;
		if cek=1 then
			begin
			break;
			end;
		end;
	if cek=0 then
		begin
		writeln('0'); 
		exit;
		end;
	cek:=0;
	for i:=1 to msk do
		begin
		for j:=1 to msk do
			begin
			if ma[i,j]<>mb[j,msk+1-i] then
				begin
				cek:=1;
				break;
				end;
			end;
		if cek=1 then
			begin
			break;
			end;
		end;
	if cek=0 then
		begin
		writeln('90');
		exit;
		end;
	cek:=0;
	for i:=1 to msk do
		begin
		for j:=1 to msk do
			begin
			if ma[i,j]<>mb[msk+1-i,msk+1-j] then
				begin
				cek:=1;
				break;
				end;
			end;
		if cek=1 then
			begin
			break;
			end;
		end;
	if cek=0 then
		begin
		writeln('180');
		exit;
		end;
	cek:=0;
	for i:=1 to msk do	
		begin
		for j:=1 to msk do	
			begin
			if ma[i,j]<>mb[msk+1-j,i] then
				begin
				cek:=1;
				break;
				end;
			end;
		if cek=1 then
			begin
			break;
			end;
		end;
	if cek=0 then
		begin
		writeln('270');
		end
	else
		begin
		writeln('tidak sama');
		end;
end.