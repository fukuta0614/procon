
/* WARNING: Removing unreachable block (ram,0x00006ff8) */
/* WARNING: Removing unreachable block (ram,0x00006038) */
/* WARNING: Removing unreachable block (ram,0x00006691) */
/* WARNING: Removing unreachable block (ram,0x00006080) */
/* WARNING: Removing unreachable block (ram,0x000068c7) */
/* WARNING: Removing unreachable block (ram,0x00006649) */
/* WARNING: Removing unreachable block (ram,0x00006fb0) */
/* WARNING: Removing unreachable block (ram,0x000062b3) */
/* WARNING: Removing unreachable block (ram,0x0000626b) */
/* WARNING: Removing unreachable block (ram,0x0000690f) */

byte _w2c_check_flag(void)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  iVar2 = _w2c_g0;
  _wasm_rt_call_stack_depth = _wasm_rt_call_stack_depth + 1;
  if (500 < _wasm_rt_call_stack_depth) {
                    /* WARNING: Subroutine does not return */
    _wasm_rt_trap(7);
  }

  uVar1 = _w2c_g0 - 0x10;
  _w2c_g0 = uVar1;
  _i32_store(&_w2c_memory,(ulong)uVar1 + 0xc,0);
  while( true ) {
    uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    cVar3 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
    if (cVar3 == '\0') break;
    uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    cVar3 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
    _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)cVar3 ^ 0x14);
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    if (0 < iVar7) {
      iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      bVar4 = _i32_load8_u(&_w2c_memory,(ulong)(iVar7 - 1) + 0x430);
      uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      bVar5 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
      _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)(char)(bVar5 ^ bVar4));
    }
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    if (2 < iVar7) {
      iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      bVar4 = _i32_load8_u(&_w2c_memory,(ulong)(iVar7 - 3) + 0x430);
      uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      bVar5 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
      _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)(char)(bVar5 ^ bVar4));
    }
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    cVar3 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
    _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)cVar3 ^ iVar7 % 10);
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    if (iVar7 % 2 == 0) {
      uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      cVar3 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
      _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)cVar3 ^ 9);
    }
    else {
      uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      cVar3 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
      _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)cVar3 ^ 8);
    }
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    if (iVar7 % 3 == 0) {
      uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      cVar3 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
      _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)cVar3 ^ 7);
    }
    else {
      iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      if (iVar7 % 3 == 1) {
        uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
        cVar3 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
        _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)cVar3 ^ 6);
      }
      else {
        uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
        cVar3 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
        _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,(int)cVar3 ^ 5);
      }
    }
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    _i32_store(&_w2c_memory,(ulong)uVar1 + 0xc,iVar7 + 1);
  }
  _i32_store(&_w2c_memory,(ulong)uVar1 + 4,0);
  while( true ) {
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 4);
    iVar8 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
    if (iVar8 <= iVar7) break;
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 4);
    if (iVar7 % 2 == 0) {
      iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 4);
      iVar8 = _i32_load(&_w2c_memory,(ulong)uVar1 + 0xc);
      if (iVar7 + 1 < iVar8) {
        uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 4);
        uVar9 = _i32_load8_u(&_w2c_memory,(ulong)uVar6 + 0x430);
        _i32_store8(&_w2c_memory,(ulong)uVar1 + 0xb,uVar9);
        iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 4);
        uVar9 = _i32_load8_u(&_w2c_memory,(ulong)(iVar7 + 1) + 0x430);
        uVar6 = _i32_load(&_w2c_memory,(ulong)uVar1 + 4);
        _i32_store8(&_w2c_memory,(ulong)uVar6 + 0x430,uVar9);
        uVar9 = _i32_load8_u(&_w2c_memory,(ulong)uVar1 + 0xb);
        iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 4);
        _i32_store8(&_w2c_memory,(ulong)(iVar7 + 1) + 0x430,uVar9);
      }
    }
    iVar7 = _i32_load(&_w2c_memory,(ulong)uVar1 + 4);
    _i32_store(&_w2c_memory,(ulong)uVar1 + 4,iVar7 + 1);
  }
  iVar7 = _w2c_strcmp(0x400,0x430,0x430);
  _wasm_rt_call_stack_depth = _wasm_rt_call_stack_depth - 1;
  _w2c_g0 = iVar2;
  return (iVar7 != 0 ^ 0xffU) & 1;
}

