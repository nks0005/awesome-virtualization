# Hypervisor


VMXON -> VMM -> VMXOFF
    
    VMEntry -> Guest VM -> VMExit


- VMM : Virtual Machine Monitor
    호스트 역할
    프로세서 + 기타 플랫폼 하드웨어를 완전히 격리
        프로세서 리소스, 물리적 메모리, 인터럽트 관리, IO에 대한 선택적 제어 

VMM -> VMX root 작업
GVM -> VMX non-root 작업

- VMCS : Virtual Machine Control Structure
    각 CPU VMCS 포인터 
    
    영역
    1. 게스트 상태 영역
    2. 호스트 상태 영역

    3. VM 실행, 종료, 진입, Exit 제어 관련

- VMX Instructions 
    INVEPT, INVVPID
    VMCALL, VMFUNC
    VMCLEAR, VMLAUNCH, VMRESUME
    VMPTRLD, VMPTRST
    VMREAD, VMWRITE
    VMXOFF, VMXON

# 하이퍼바이저 지원 감지
    CPUID(1).ECX.VMX[bit 5] == 1

## 인텔 CPU 확인
    CPUID(0) == "GenuineIntel"

## VMX 확인
    CPUID(1).ECX[bit 5] == 1

# VMX 작업 활성화
    CR4.VMXE[bit 13] = 1로 설정 

    VMXON + IA32_FEATURE_CONTROL MSR 

# VMXON 필드 
    VMXON Field + VMCS 

    4kb, 4kb 정렬

# VMLaunch, VMclear, VMptrld ...

# MSR_IA32_VMS_BASIC
    Intel의 가상화 기술인 VT-x에서 사용하는 Machine-Specific-Register . MSR
    
    1. Revision Identifier 
        VMXON 영역, VMCS의 데이터 구조에 대한 버전 정보. 
            Hypervisor는 이 값으로 프로세서가 지원되는 데이터 머신 구조 정보를 얻는다.

