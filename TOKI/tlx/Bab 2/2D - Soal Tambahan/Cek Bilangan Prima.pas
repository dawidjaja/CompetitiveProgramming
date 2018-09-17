var
    msk,i:longint;
begin
    while not eof do
        begin
        readln(msk);
        if msk<2 then
            begin
            writeln('TIDAK');
            continue;
            end;
        if msk<4 then
            begin
            writeln('YA');
            continue;
            end;
        for i:=2 to msk-2 do
            begin
            if (msk mod i=0) then
                begin
                writeln ('TIDAK');
                break;
                end
            else
                begin
                writeln('YA');
                break;
                end;
            end;
        end;
end.