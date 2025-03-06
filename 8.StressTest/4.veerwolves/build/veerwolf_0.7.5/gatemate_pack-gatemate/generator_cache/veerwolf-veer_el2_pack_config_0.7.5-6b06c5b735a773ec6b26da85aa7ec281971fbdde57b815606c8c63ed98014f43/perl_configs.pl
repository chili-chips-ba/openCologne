#  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE
#  This is an automatically generated file by tarik on Čet 06 Mar 2025 11:08:14 CET
# 
#  cmd:    veer -unset=assert_on -set=reset_vec=0x80000000 -set=fpga_optimize=1 -set=ret_stack_size=2 -set=btb_size=32 -set=bht_size=128 -set=dccm_size=16 -set=dccm_num_banks=2 -set=iccm_enable=0 -set=icache_enable=0 -set=dccm_enable=0 -set=pic_total_int=8 
# 
# To use this in a perf script, use 'require $RV_ROOT/configs/config.pl'
# Reference the hash via $config{name}..


%config = (
            'pic' => {
                       'pic_meigwclr_count' => 8,
                       'pic_meipl_offset' => '0x0000',
                       'pic_meipt_count' => 8,
                       'pic_meigwclr_offset' => '0x5000',
                       'pic_meigwctrl_offset' => '0x4000',
                       'pic_offset' => '0xc0000',
                       'pic_mpiccfg_count' => 1,
                       'pic_mpiccfg_mask' => '0x1',
                       'pic_total_int_plus1' => 9,
                       'pic_bits' => 15,
                       'pic_meipt_offset' => '0x3004',
                       'pic_meipl_count' => 8,
                       'pic_size' => 32,
                       'pic_meie_count' => 8,
                       'pic_mpiccfg_offset' => '0x3000',
                       'pic_meipt_mask' => '0x0',
                       'pic_meip_mask' => '0x0',
                       'pic_meip_offset' => '0x1000',
                       'pic_total_int' => 8,
                       'pic_meigwclr_mask' => '0x0',
                       'pic_meipl_mask' => '0xf',
                       'pic_meie_offset' => '0x2000',
                       'pic_meie_mask' => '0x1',
                       'pic_region' => '0xf',
                       'pic_base_addr' => '0xf00c0000',
                       'pic_meip_count' => 1,
                       'pic_meigwctrl_count' => 8,
                       'pic_int_words' => 1,
                       'pic_meigwctrl_mask' => '0x3'
                     },
            'testbench' => {
                             'TOP' => 'tb_top',
                             'ext_addrwidth' => '32',
                             'build_axi4' => 1,
                             'assert_on' => '',
                             'sterr_rollback' => '0',
                             'ext_datawidth' => '64',
                             'clock_period' => '100',
                             'lderr_rollback' => '1',
                             'build_axi_native' => 1,
                             'CPU_TOP' => '`RV_TOP.swerv',
                             'SDVT_AHB' => '0',
                             'RV_TOP' => '`TOP.rvtop'
                           },
            'csr' => {
                       'pmpaddr8' => {
                                       'exists' => 'false'
                                     },
                       'pmpaddr15' => {
                                        'exists' => 'false'
                                      },
                       'dicago' => {
                                     'reset' => '0x0',
                                     'number' => '0x7cb',
                                     'debug' => 'true',
                                     'mask' => '0x0',
                                     'comment' => 'Cache diagnostics.',
                                     'exists' => 'true'
                                   },
                       'time' => {
                                   'exists' => 'false'
                                 },
                       'mhpmevent6' => {
                                         'mask' => '0xffffffff',
                                         'exists' => 'true',
                                         'reset' => '0x0'
                                       },
                       'mhpmcounter5' => {
                                           'exists' => 'true',
                                           'mask' => '0xffffffff',
                                           'reset' => '0x0'
                                         },
                       'pmpaddr0' => {
                                       'exists' => 'false'
                                     },
                       'mhpmcounter3h' => {
                                            'mask' => '0xffffffff',
                                            'exists' => 'true',
                                            'reset' => '0x0'
                                          },
                       'marchid' => {
                                      'reset' => '0x00000010',
                                      'exists' => 'true',
                                      'mask' => '0x0'
                                    },
                       'meicpct' => {
                                      'reset' => '0x0',
                                      'number' => '0xbca',
                                      'mask' => '0x0',
                                      'comment' => 'External claim id/priority capture.',
                                      'exists' => 'true'
                                    },
                       'meicurpl' => {
                                       'comment' => 'External interrupt current priority level.',
                                       'exists' => 'true',
                                       'mask' => '0xf',
                                       'reset' => '0x0',
                                       'number' => '0xbcc'
                                     },
                       'mcounteren' => {
                                         'exists' => 'false'
                                       },
                       'dmst' => {
                                   'comment' => 'Memory synch trigger: Flush caches in debug mode.',
                                   'exists' => 'true',
                                   'mask' => '0x0',
                                   'debug' => 'true',
                                   'reset' => '0x0',
                                   'number' => '0x7c4'
                                 },
                       'pmpaddr1' => {
                                       'exists' => 'false'
                                     },
                       'dicad0' => {
                                     'exists' => 'true',
                                     'comment' => 'Cache diagnostics.',
                                     'mask' => '0xffffffff',
                                     'debug' => 'true',
                                     'number' => '0x7c9',
                                     'reset' => '0x0'
                                   },
                       'dicawics' => {
                                       'comment' => 'Cache diagnostics.',
                                       'exists' => 'true',
                                       'mask' => '0x0130fffc',
                                       'debug' => 'true',
                                       'reset' => '0x0',
                                       'number' => '0x7c8'
                                     },
                       'mhpmcounter4' => {
                                           'reset' => '0x0',
                                           'exists' => 'true',
                                           'mask' => '0xffffffff'
                                         },
                       'pmpaddr13' => {
                                        'exists' => 'false'
                                      },
                       'pmpaddr2' => {
                                       'exists' => 'false'
                                     },
                       'meicidpl' => {
                                       'mask' => '0xf',
                                       'comment' => 'External interrupt claim id priority level.',
                                       'exists' => 'true',
                                       'reset' => '0x0',
                                       'number' => '0xbcb'
                                     },
                       'meipt' => {
                                    'mask' => '0xf',
                                    'comment' => 'External interrupt priority threshold.',
                                    'exists' => 'true',
                                    'reset' => '0x0',
                                    'number' => '0xbc9'
                                  },
                       'mfdhs' => {
                                    'exists' => 'true',
                                    'comment' => 'Force Debug Halt Status',
                                    'mask' => '0x00000003',
                                    'number' => '0x7cf',
                                    'reset' => '0x0'
                                  },
                       'mitcnt1' => {
                                      'number' => '0x7d5',
                                      'reset' => '0x0',
                                      'exists' => 'true',
                                      'mask' => '0xffffffff'
                                    },
                       'mstatus' => {
                                      'mask' => '0x88',
                                      'exists' => 'true',
                                      'reset' => '0x1800'
                                    },
                       'mie' => {
                                  'reset' => '0x0',
                                  'mask' => '0x70000888',
                                  'exists' => 'true'
                                },
                       'pmpaddr10' => {
                                        'exists' => 'false'
                                      },
                       'pmpaddr9' => {
                                       'exists' => 'false'
                                     },
                       'mhpmcounter6h' => {
                                            'reset' => '0x0',
                                            'exists' => 'true',
                                            'mask' => '0xffffffff'
                                          },
                       'mfdc' => {
                                   'exists' => 'true',
                                   'mask' => '0x00071fff',
                                   'number' => '0x7f9',
                                   'reset' => '0x00070040'
                                 },
                       'mpmc' => {
                                   'mask' => '0x2',
                                   'exists' => 'true',
                                   'number' => '0x7c6',
                                   'reset' => '0x2'
                                 },
                       'pmpcfg1' => {
                                      'exists' => 'false'
                                    },
                       'pmpaddr3' => {
                                       'exists' => 'false'
                                     },
                       'pmpaddr7' => {
                                       'exists' => 'false'
                                     },
                       'tselect' => {
                                      'reset' => '0x0',
                                      'exists' => 'true',
                                      'mask' => '0x3'
                                    },
                       'miccmect' => {
                                       'mask' => '0xffffffff',
                                       'exists' => 'true',
                                       'number' => '0x7f1',
                                       'reset' => '0x0'
                                     },
                       'mitbnd1' => {
                                      'reset' => '0xffffffff',
                                      'number' => '0x7d6',
                                      'exists' => 'true',
                                      'mask' => '0xffffffff'
                                    },
                       'micect' => {
                                     'mask' => '0xffffffff',
                                     'exists' => 'true',
                                     'reset' => '0x0',
                                     'number' => '0x7f0'
                                   },
                       'mfdht' => {
                                    'mask' => '0x0000003f',
                                    'exists' => 'true',
                                    'comment' => 'Force Debug Halt Threshold',
                                    'number' => '0x7ce',
                                    'reset' => '0x0',
                                    'shared' => 'true'
                                  },
                       'misa' => {
                                   'exists' => 'true',
                                   'mask' => '0x0',
                                   'reset' => '0x40001104'
                                 },
                       'mitctl0' => {
                                      'number' => '0x7d4',
                                      'reset' => '0x1',
                                      'mask' => '0x00000007',
                                      'exists' => 'true'
                                    },
                       'mhpmcounter3' => {
                                           'exists' => 'true',
                                           'mask' => '0xffffffff',
                                           'reset' => '0x0'
                                         },
                       'mvendorid' => {
                                        'exists' => 'true',
                                        'mask' => '0x0',
                                        'reset' => '0x45'
                                      },
                       'mhpmevent5' => {
                                         'exists' => 'true',
                                         'mask' => '0xffffffff',
                                         'reset' => '0x0'
                                       },
                       'mhartid' => {
                                      'reset' => '0x0',
                                      'poke_mask' => '0xfffffff0',
                                      'mask' => '0x0',
                                      'exists' => 'true'
                                    },
                       'dcsr' => {
                                   'exists' => 'true',
                                   'mask' => '0x00008c04',
                                   'debug' => 'true',
                                   'poke_mask' => '0x00008dcc',
                                   'reset' => '0x40000003'
                                 },
                       'pmpcfg3' => {
                                      'exists' => 'false'
                                    },
                       'mhpmcounter5h' => {
                                            'mask' => '0xffffffff',
                                            'exists' => 'true',
                                            'reset' => '0x0'
                                          },
                       'mdccmect' => {
                                       'number' => '0x7f2',
                                       'reset' => '0x0',
                                       'exists' => 'true',
                                       'mask' => '0xffffffff'
                                     },
                       'mip' => {
                                  'reset' => '0x0',
                                  'poke_mask' => '0x70000888',
                                  'mask' => '0x0',
                                  'exists' => 'true'
                                },
                       'instret' => {
                                      'exists' => 'false'
                                    },
                       'pmpaddr14' => {
                                        'exists' => 'false'
                                      },
                       'mcgc' => {
                                   'reset' => '0x200',
                                   'number' => '0x7f8',
                                   'poke_mask' => '0x000003ff',
                                   'mask' => '0x000003ff',
                                   'exists' => 'true'
                                 },
                       'mcountinhibit' => {
                                            'poke_mask' => '0x7d',
                                            'commnet' => 'Performance counter inhibit. One bit per counter.',
                                            'reset' => '0x0',
                                            'exists' => 'true',
                                            'mask' => '0x7d'
                                          },
                       'pmpaddr5' => {
                                       'exists' => 'false'
                                     },
                       'dicad1' => {
                                     'reset' => '0x0',
                                     'number' => '0x7ca',
                                     'debug' => 'true',
                                     'mask' => '0x3',
                                     'comment' => 'Cache diagnostics.',
                                     'exists' => 'true'
                                   },
                       'mrac' => {
                                   'reset' => '0x0',
                                   'number' => '0x7c0',
                                   'shared' => 'true',
                                   'mask' => '0xffffffff',
                                   'comment' => 'Memory region io and cache control.',
                                   'exists' => 'true'
                                 },
                       'pmpaddr4' => {
                                       'exists' => 'false'
                                     },
                       'mhpmevent3' => {
                                         'mask' => '0xffffffff',
                                         'exists' => 'true',
                                         'reset' => '0x0'
                                       },
                       'pmpaddr12' => {
                                        'exists' => 'false'
                                      },
                       'pmpcfg2' => {
                                      'exists' => 'false'
                                    },
                       'mimpid' => {
                                     'reset' => '0x4',
                                     'mask' => '0x0',
                                     'exists' => 'true'
                                   },
                       'mcpc' => {
                                   'comment' => 'Core pause',
                                   'exists' => 'true',
                                   'mask' => '0x0',
                                   'reset' => '0x0',
                                   'number' => '0x7c2'
                                 },
                       'pmpcfg0' => {
                                      'exists' => 'false'
                                    },
                       'mhpmcounter6' => {
                                           'reset' => '0x0',
                                           'exists' => 'true',
                                           'mask' => '0xffffffff'
                                         },
                       'pmpaddr6' => {
                                       'exists' => 'false'
                                     },
                       'mitcnt0' => {
                                      'exists' => 'true',
                                      'mask' => '0xffffffff',
                                      'number' => '0x7d2',
                                      'reset' => '0x0'
                                    },
                       'mscause' => {
                                      'mask' => '0x0000000f',
                                      'exists' => 'true',
                                      'number' => '0x7ff',
                                      'reset' => '0x0'
                                    },
                       'mhpmcounter4h' => {
                                            'reset' => '0x0',
                                            'mask' => '0xffffffff',
                                            'exists' => 'true'
                                          },
                       'cycle' => {
                                    'exists' => 'false'
                                  },
                       'mhpmevent4' => {
                                         'reset' => '0x0',
                                         'exists' => 'true',
                                         'mask' => '0xffffffff'
                                       },
                       'mitctl1' => {
                                      'number' => '0x7d7',
                                      'reset' => '0x1',
                                      'exists' => 'true',
                                      'mask' => '0x0000000f'
                                    },
                       'mitbnd0' => {
                                      'exists' => 'true',
                                      'mask' => '0xffffffff',
                                      'number' => '0x7d3',
                                      'reset' => '0xffffffff'
                                    },
                       'pmpaddr11' => {
                                        'exists' => 'false'
                                      }
                     },
            'perf_events' => [
                               1,
                               2,
                               3,
                               4,
                               5,
                               6,
                               7,
                               8,
                               9,
                               10,
                               11,
                               12,
                               13,
                               14,
                               15,
                               16,
                               17,
                               18,
                               19,
                               20,
                               21,
                               22,
                               23,
                               24,
                               25,
                               26,
                               27,
                               28,
                               30,
                               31,
                               32,
                               34,
                               35,
                               36,
                               37,
                               38,
                               39,
                               40,
                               41,
                               42,
                               43,
                               44,
                               45,
                               46,
                               47,
                               48,
                               49,
                               50,
                               54,
                               55,
                               56,
                               512,
                               513,
                               514,
                               515,
                               516
                             ],
            'harts' => 1,
            'physical' => '1',
            'tec_rv_icg' => 'clockhdr',
            'iccm' => {
                        'iccm_bank_index_lo' => 4,
                        'iccm_size_64' => '',
                        'iccm_region' => '0xe',
                        'iccm_eadr' => '0xee00ffff',
                        'iccm_num_banks' => '4',
                        'iccm_reserved' => '0x1000',
                        'iccm_bank_bits' => 2,
                        'iccm_num_banks_4' => '',
                        'iccm_bank_hi' => 3,
                        'iccm_data_cell' => 'ram_4096x39',
                        'iccm_offset' => '0xe000000',
                        'iccm_size' => 64,
                        'iccm_sadr' => '0xee000000',
                        'iccm_bits' => 16,
                        'iccm_rows' => '4096',
                        'iccm_index_bits' => 12
                      },
            'dccm' => {
                        'dccm_data_cell' => 'ram_2048x39',
                        'dccm_fdata_width' => 39,
                        'dccm_bank_bits' => 1,
                        'dccm_reserved' => '0x1400',
                        'dccm_offset' => '0x40000',
                        'dccm_size_16' => '',
                        'dccm_width_bits' => 2,
                        'lsu_sb_bits' => 14,
                        'dccm_num_banks' => '2',
                        'dccm_eadr' => '0xf0043fff',
                        'dccm_region' => '0xf',
                        'dccm_index_bits' => 11,
                        'dccm_ecc_width' => 7,
                        'dccm_data_width' => 32,
                        'dccm_size' => 16,
                        'dccm_rows' => '2048',
                        'dccm_num_banks_2' => '',
                        'dccm_bits' => 14,
                        'dccm_byte_width' => '4',
                        'dccm_sadr' => '0xf0040000'
                      },
            'regwidth' => '32',
            'target' => 'default',
            'bht' => {
                       'bht_addr_hi' => 7,
                       'bht_addr_lo' => '2',
                       'bht_array_depth' => 64,
                       'bht_ghr_range' => '5:0',
                       'bht_size' => 128,
                       'bht_ghr_hash_1' => 1,
                       'bht_hash_string' => '{ghr[5:4], hashin[5:2]^ghr[4-1:0]} // cf1',
                       'bht_ghr_size' => 6
                     },
            'btb' => {
                       'btb_index2_hi' => 9,
                       'btb_index1_lo' => '2',
                       'btb_array_depth' => 16,
                       'btb_size' => 32,
                       'btb_index3_hi' => 13,
                       'btb_fold2_index_hash' => 0,
                       'btb_btag_fold' => 1,
                       'btb_addr_hi' => 5,
                       'btb_toffset_size' => '12',
                       'btb_index2_lo' => 6,
                       'btb_index1_hi' => 5,
                       'btb_btag_size' => 9,
                       'btb_enable' => '1',
                       'btb_index3_lo' => 10,
                       'btb_addr_lo' => '2'
                     },
            'xlen' => 32,
            'max_mmode_perf_event' => '516',
            'triggers' => [
                            {
                              'reset' => [
                                           '0x23e00000',
                                           '0x00000000',
                                           '0x00000000'
                                         ],
                              'poke_mask' => [
                                               '0x081818c7',
                                               '0xffffffff',
                                               '0x00000000'
                                             ],
                              'mask' => [
                                          '0x081818c7',
                                          '0xffffffff',
                                          '0x00000000'
                                        ]
                            },
                            {
                              'mask' => [
                                          '0x081810c7',
                                          '0xffffffff',
                                          '0x00000000'
                                        ],
                              'poke_mask' => [
                                               '0x081810c7',
                                               '0xffffffff',
                                               '0x00000000'
                                             ],
                              'reset' => [
                                           '0x23e00000',
                                           '0x00000000',
                                           '0x00000000'
                                         ]
                            },
                            {
                              'poke_mask' => [
                                               '0x081818c7',
                                               '0xffffffff',
                                               '0x00000000'
                                             ],
                              'reset' => [
                                           '0x23e00000',
                                           '0x00000000',
                                           '0x00000000'
                                         ],
                              'mask' => [
                                          '0x081818c7',
                                          '0xffffffff',
                                          '0x00000000'
                                        ]
                            },
                            {
                              'mask' => [
                                          '0x081810c7',
                                          '0xffffffff',
                                          '0x00000000'
                                        ],
                              'reset' => [
                                           '0x23e00000',
                                           '0x00000000',
                                           '0x00000000'
                                         ],
                              'poke_mask' => [
                                               '0x081810c7',
                                               '0xffffffff',
                                               '0x00000000'
                                             ]
                            }
                          ],
            'core' => {
                        'lsu_num_nbload_width' => '2',
                        'icache_only' => 'derived',
                        'bitmanip_zbb' => 1,
                        'bitmanip_zba' => 1,
                        'no_iccm_no_icache' => 1,
                        'bitmanip_zbp' => 0,
                        'bitmanip_zbr' => 0,
                        'div_new' => 1,
                        'lsu_stbuf_depth' => '4',
                        'bitmanip_zbf' => 0,
                        'fpga_optimize' => 1,
                        'dma_buf_depth' => '5',
                        'div_bit' => '4',
                        'lsu2dma' => 0,
                        'timer_legal_en' => '1',
                        'bitmanip_zbe' => 0,
                        'iccm_only' => 'derived',
                        'iccm_icache' => 'derived',
                        'fast_interrupt_redirect' => 0,
                        'lsu_num_nbload' => '4',
                        'bitmanip_zbc' => 1,
                        'bitmanip_zbs' => 1
                      },
            'config_key' => '32\'hdeadbeef',
            'nmi_vec' => '0x11110000',
            'memmap' => {
                          'external_data_1' => '0xb0000000',
                          'unused_region1' => '0x70000000',
                          'unused_region4' => '0x40000000',
                          'unused_region8' => '0x00000000',
                          'consoleio' => '0xd0580000',
                          'unused_region0' => '0x90000000',
                          'serialio' => '0xd0580000',
                          'debug_sb_mem' => '0xa0580000',
                          'unused_region6' => '0x20000000',
                          'unused_region5' => '0x30000000',
                          'unused_region3' => '0x50000000',
                          'unused_region7' => '0x10000000',
                          'unused_region2' => '0x60000000',
                          'external_data' => '0xc0580000'
                        },
            'retstack' => {
                            'ret_stack_size' => '2'
                          },
            'numiregs' => '32',
            'icache' => {
                          'icache_tag_lo' => 13,
                          'icache_data_index_lo' => 4,
                          'icache_bank_bits' => 1,
                          'icache_num_lines' => 256,
                          'icache_ecc' => '1',
                          'icache_tag_num_bypass' => '2',
                          'icache_ln_sz' => 64,
                          'icache_data_depth' => '512',
                          'icache_bank_lo' => 3,
                          'icache_tag_num_bypass_width' => 2,
                          'icache_size' => 16,
                          'icache_scnd_last' => 6,
                          'icache_beat_addr_hi' => 5,
                          'icache_index_hi' => 12,
                          'icache_tag_index_lo' => '6',
                          'icache_num_bypass' => '2',
                          'icache_data_width' => 64,
                          'icache_tag_depth' => 128,
                          'icache_data_cell' => 'ram_512x71',
                          'icache_num_bypass_width' => 2,
                          'icache_waypack' => '1',
                          'icache_fdata_width' => 71,
                          'icache_num_lines_bank' => '64',
                          'icache_num_lines_way' => '128',
                          'icache_banks_way' => 2,
                          'icache_num_beats' => 8,
                          'icache_status_bits' => 1,
                          'icache_bank_hi' => 3,
                          'icache_bank_width' => 8,
                          'icache_beat_bits' => 3,
                          'icache_bypass_enable' => '1',
                          'icache_tag_cell' => 'ram_128x25',
                          'icache_tag_bypass_enable' => '1',
                          'icache_2banks' => '1',
                          'icache_num_ways' => 2
                        },
            'protection' => {
                              'inst_access_enable1' => '0x0',
                              'data_access_mask1' => '0xffffffff',
                              'data_access_mask4' => '0xffffffff',
                              'inst_access_addr1' => '0x00000000',
                              'inst_access_addr4' => '0x00000000',
                              'inst_access_enable3' => '0x0',
                              'data_access_enable5' => '0x0',
                              'data_access_enable6' => '0x0',
                              'inst_access_enable5' => '0x0',
                              'inst_access_enable6' => '0x0',
                              'data_access_enable3' => '0x0',
                              'data_access_addr4' => '0x00000000',
                              'data_access_addr1' => '0x00000000',
                              'inst_access_mask4' => '0xffffffff',
                              'inst_access_mask1' => '0xffffffff',
                              'data_access_enable1' => '0x0',
                              'data_access_addr7' => '0x00000000',
                              'data_access_addr2' => '0x00000000',
                              'inst_access_mask0' => '0xffffffff',
                              'data_access_addr0' => '0x00000000',
                              'inst_access_enable0' => '0x0',
                              'data_access_enable7' => '0x0',
                              'inst_access_mask2' => '0xffffffff',
                              'inst_access_mask7' => '0xffffffff',
                              'data_access_mask2' => '0xffffffff',
                              'data_access_mask7' => '0xffffffff',
                              'inst_access_enable7' => '0x0',
                              'data_access_enable0' => '0x0',
                              'inst_access_addr0' => '0x00000000',
                              'data_access_mask0' => '0xffffffff',
                              'inst_access_addr7' => '0x00000000',
                              'inst_access_addr2' => '0x00000000',
                              'inst_access_enable2' => '0x0',
                              'data_access_addr6' => '0x00000000',
                              'inst_access_mask6' => '0xffffffff',
                              'data_access_mask6' => '0xffffffff',
                              'inst_access_addr6' => '0x00000000',
                              'data_access_enable2' => '0x0',
                              'inst_access_enable4' => '0x0',
                              'inst_access_mask5' => '0xffffffff',
                              'data_access_addr3' => '0x00000000',
                              'inst_access_mask3' => '0xffffffff',
                              'data_access_addr5' => '0x00000000',
                              'data_access_mask3' => '0xffffffff',
                              'inst_access_addr5' => '0x00000000',
                              'data_access_mask5' => '0xffffffff',
                              'inst_access_addr3' => '0x00000000',
                              'data_access_enable4' => '0x0'
                            },
            'num_mmode_perf_regs' => '4',
            'even_odd_trigger_chains' => 'true',
            'reset_vec' => '0x80000000',
            'bus' => {
                       'dma_bus_tag' => '1',
                       'bus_prty_default' => '3',
                       'lsu_bus_id' => '1',
                       'sb_bus_prty' => '2',
                       'ifu_bus_tag' => '3',
                       'lsu_bus_prty' => '2',
                       'sb_bus_tag' => '1',
                       'dma_bus_prty' => '2',
                       'dma_bus_id' => '1',
                       'ifu_bus_id' => '1',
                       'ifu_bus_prty' => '2',
                       'sb_bus_id' => '1',
                       'lsu_bus_tag' => 3
                     }
          );
1;
