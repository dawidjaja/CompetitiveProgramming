var
	mx,my,iy,ix,bx,by,kx,ky:int64;
	brs:ansistring;
	tnd:array[0..1000,0..1000] of longint;
	qx,qy:array[0..10000] of longint;
begin
	readln(mx,my);
	for iy:=1 to my do
		begin
		for ix:=1 to mx do
			begin
			tnd[iy,ix]:=0;
			end;
		end;
	for iy:=1 to my do
		begin
		readln(brs);
		for ix:=1 to mx do
			begin
			if brs[ix]='#' then
				begin
				tnd[iy,ix]:=1;
				end;
			if brs[ix]='B' then
				begin
				bx:=ix;
				by:=iy;
				tnd[iy,ix]:=2;
				end;
			if brs[ix]='K' then
				begin
				kx:=ix;
				ky:=iy;
				tnd[iy,ix]:=2;
				end;
			end;
		end;
	qy[1]:=by;
	qx[1]:=bx;
	
end.