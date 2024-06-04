import type {TurboModule} from 'react-native';
// import type {TurboModule} from 'react-native'; in future versions
import {TurboModuleRegistry} from 'react-native';

export type ConstantsStruct = {
  const1: boolean;
  const2: number;
  const3: string;
};

export interface Spec extends TurboModule {
  readonly reverseString: (input: string) => string;
  getConstants: () => ConstantsStruct;
}

export default TurboModuleRegistry.getEnforcing<Spec>('NativeCppModule');
