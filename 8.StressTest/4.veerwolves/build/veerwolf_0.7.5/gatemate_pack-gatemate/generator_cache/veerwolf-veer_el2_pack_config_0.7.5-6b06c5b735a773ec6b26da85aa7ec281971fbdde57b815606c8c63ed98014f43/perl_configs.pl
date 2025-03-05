#  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE
#  This is an automatically generated file by tarik on Sri 05 Mar 2025 22:47:46 CET
# 
#  cmd:    veer -unset=assert_on -set=reset_vec=0x80000000 -set=fpga_optimize=1 -set=ret_stack_size=2 -set=btb_size=32 -set=bht_size=128 -set=dccm_size=16 -set=dccm_num_banks=2 -set=iccm_enable=0 -set=icache_enable=0 -set=dccm_enable=0 -set=pic_total_int=8 
# 
# To use this in a perf script, use 'require $RV_ROOT/configs/config.pl'
# Reference the hash via $config{name}..


%config = (
            'xlen' => 32,
            'regwidth' => '32',
            'testbench' => {
                             'CPU_TOP' => '`RV_TOP.veer',
                             'sterr_rollback' => '0',
                             'SDVT_AHB' => '0',
                             'clock_period' => '100',
                             'lderr_rollback' => '1',
                             'ext_addrwidth' => '32',
                             'ext_datawidth' => '64',
                             'build_axi_native' => 1,
                             'build_axi4' => 1,
                             'assert_on' => '',
                             'RV_TOP' => '`TOP.rvtop',
                             'TOP' => 'tb_top'
                           },
            'harts' => 1,
            'pic' => {
                       'pic_size' => 32,
                       'pic_meie_mask' => '0x1',
                       'pic_meigwclr_mask' => '0x0',
                       'pic_mpiccfg_offset' => '0x3000',
                       'pic_total_int' => 8,
                       'pic_meie_count' => 8,
                       'pic_meipt_mask' => '0x0',
                       'pic_meipt_count' => 8,
                       'pic_mpiccfg_mask' => '0x1',
                       'pic_meigwclr_count' => 8,
                       'pic_meip_offset' => '0x1000',
                       'pic_offset' => '0xc0000',
                       'pic_region' => '0xf',
                       'pic_meigwctrl_offset' => '0x4000',
                       'pic_meipl_count' => 8,
                       'pic_mpiccfg_count' => 1,
                       'pic_meipl_mask' => '0xf',
                       'pic_meipt_offset' => '0x3004',
                       'pic_meie_offset' => '0x2000',
                       'pic_meip_count' => 1,
                       'pic_meigwctrl_mask' => '0x3',
                       'pic_meip_mask' => '0x0',
                       'pic_base_addr' => '0xf00c0000',
                       'pic_total_int_plus1' => 9,
                       'pic_int_words' => 1,
                       'pic_meigwctrl_count' => 8,
                       'pic_bits' => 15,
                       'pic_meigwclr_offset' => '0x5000',
                       'pic_meipl_offset' => '0x0000'
                     },
            'max_mmode_perf_event' => '516',
            'even_odd_trigger_chains' => 'true',
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
            'core' => {
                        'fast_interrupt_redirect' => 0,
                        'div_new' => 1,
                        'lsu_stbuf_depth' => '4',
                        'bitmanip_zbf' => 0,
                        'iccm_icache' => 'derived',
                        'dma_buf_depth' => '5',
                        'lsu_num_nbload' => '4',
                        'bitmanip_zbp' => 0,
                        'div_bit' => '4',
                        'no_iccm_no_icache' => 1,
                        'lsu_num_nbload_width' => '2',
                        'bitmanip_zba' => 1,
                        'bitmanip_zbs' => 1,
                        'bitmanip_zbe' => 0,
                        'lsu2dma' => 0,
                        'iccm_only' => 'derived',
                        'bitmanip_zbb' => 1,
                        'fpga_optimize' => 1,
                        'icache_only' => 'derived',
                        'bitmanip_zbr' => 0,
                        'timer_legal_en' => '1',
                        'bitmanip_zbc' => 1
                      },
            'retstack' => {
                            'ret_stack_size' => '2'
                          },
            'physical' => '1',
            'config_key' => '32\'hdeadbeef',
            'protection' => {
                              'data_access_enable4' => '0x0',
                              'data_access_enable3' => '0x0',
                              'data_access_mask0' => '0xffffffff',
                              'inst_access_mask3' => '0xffffffff',
                              'inst_access_enable5' => '0x0',
                              'data_access_addr2' => '0x00000000',
                              'inst_access_addr4' => '0x00000000',
                              'data_access_enable2' => '0x0',
                              'inst_access_addr5' => '0x00000000',
                              'data_access_enable0' => '0x0',
                              'data_access_mask7' => '0xffffffff',
                              'inst_access_addr6' => '0x00000000',
                              'inst_access_mask1' => '0xffffffff',
                              'inst_access_enable1' => '0x0',
                              'inst_access_mask5' => '0xffffffff',
                              'inst_access_addr1' => '0x00000000',
                              'data_access_addr7' => '0x00000000',
                              'inst_access_mask6' => '0xffffffff',
                              'data_access_enable7' => '0x0',
                              'inst_access_enable6' => '0x0',
                              'data_access_addr0' => '0x00000000',
                              'inst_access_addr3' => '0x00000000',
                              'data_access_mask2' => '0xffffffff',
                              'inst_access_mask4' => '0xffffffff',
                              'data_access_mask3' => '0xffffffff',
                              'data_access_addr4' => '0x00000000',
                              'inst_access_addr2' => '0x00000000',
                              'data_access_enable5' => '0x0',
                              'inst_access_enable4' => '0x0',
                              'inst_access_mask0' => '0xffffffff',
                              'inst_access_enable3' => '0x0',
                              'data_access_enable1' => '0x0',
                              'data_access_addr5' => '0x00000000',
                              'inst_access_enable2' => '0x0',
                              'inst_access_mask7' => '0xffffffff',
                              'data_access_mask1' => '0xffffffff',
                              'inst_access_enable0' => '0x0',
                              'data_access_addr6' => '0x00000000',
                              'inst_access_enable7' => '0x0',
                              'data_access_mask5' => '0xffffffff',
                              'data_access_addr1' => '0x00000000',
                              'data_access_mask6' => '0xffffffff',
                              'inst_access_addr7' => '0x00000000',
                              'data_access_addr3' => '0x00000000',
                              'data_access_mask4' => '0xffffffff',
                              'inst_access_mask2' => '0xffffffff',
                              'inst_access_addr0' => '0x00000000',
                              'data_access_enable6' => '0x0'
                            },
            'csr' => {
                       'mie' => {
                                  'reset' => '0x0',
                                  'exists' => 'true',
                                  'mask' => '0x70000888'
                                },
                       'mhpmcounter5h' => {
                                            'exists' => 'true',
                                            'reset' => '0x0',
                                            'mask' => '0xffffffff'
                                          },
                       'mitcnt0' => {
                                      'number' => '0x7d2',
                                      'reset' => '0x0',
                                      'exists' => 'true',
                                      'mask' => '0xffffffff'
                                    },
                       'micect' => {
                                     'mask' => '0xffffffff',
                                     'number' => '0x7f0',
                                     'reset' => '0x0',
                                     'exists' => 'true'
                                   },
                       'mcounteren' => {
                                         'exists' => 'false'
                                       },
                       'dicad1' => {
                                     'debug' => 'true',
                                     'mask' => '0x3',
                                     'comment' => 'Cache diagnostics.',
                                     'number' => '0x7ca',
                                     'reset' => '0x0',
                                     'exists' => 'true'
                                   },
                       'pmpaddr8' => {
                                       'exists' => 'false'
                                     },
                       'meicurpl' => {
                                       'exists' => 'true',
                                       'reset' => '0x0',
                                       'number' => '0xbcc',
                                       'comment' => 'External interrupt current priority level.',
                                       'mask' => '0xf'
                                     },
                       'miccmect' => {
                                       'mask' => '0xffffffff',
                                       'number' => '0x7f1',
                                       'exists' => 'true',
                                       'reset' => '0x0'
                                     },
                       'meipt' => {
                                    'mask' => '0xf',
                                    'number' => '0xbc9',
                                    'reset' => '0x0',
                                    'exists' => 'true',
                                    'comment' => 'External interrupt priority threshold.'
                                  },
                       'pmpaddr4' => {
                                       'exists' => 'false'
                                     },
                       'dicago' => {
                                     'number' => '0x7cb',
                                     'reset' => '0x0',
                                     'exists' => 'true',
                                     'comment' => 'Cache diagnostics.',
                                     'mask' => '0x0',
                                     'debug' => 'true'
                                   },
                       'mfdhs' => {
                                    'comment' => 'Force Debug Halt Status',
                                    'exists' => 'true',
                                    'reset' => '0x0',
                                    'number' => '0x7cf',
                                    'mask' => '0x00000003'
                                  },
                       'meicidpl' => {
                                       'comment' => 'External interrupt claim id priority level.',
                                       'reset' => '0x0',
                                       'exists' => 'true',
                                       'number' => '0xbcb',
                                       'mask' => '0xf'
                                     },
                       'pmpcfg3' => {
                                      'exists' => 'false'
                                    },
                       'tselect' => {
                                      'reset' => '0x0',
                                      'exists' => 'true',
                                      'mask' => '0x3'
                                    },
                       'mhpmcounter4h' => {
                                            'mask' => '0xffffffff',
                                            'reset' => '0x0',
                                            'exists' => 'true'
                                          },
                       'pmpcfg2' => {
                                      'exists' => 'false'
                                    },
                       'mip' => {
                                  'poke_mask' => '0x70000888',
                                  'mask' => '0x0',
                                  'exists' => 'true',
                                  'reset' => '0x0'
                                },
                       'pmpaddr9' => {
                                       'exists' => 'false'
                                     },
                       'pmpaddr12' => {
                                        'exists' => 'false'
                                      },
                       'mitbnd0' => {
                                      'number' => '0x7d3',
                                      'reset' => '0xffffffff',
                                      'exists' => 'true',
                                      'mask' => '0xffffffff'
                                    },
                       'mfdc' => {
                                   'mask' => '0x00071fff',
                                   'number' => '0x7f9',
                                   'reset' => '0x00070040',
                                   'exists' => 'true'
                                 },
                       'pmpaddr0' => {
                                       'exists' => 'false'
                                     },
                       'mhpmcounter4' => {
                                           'mask' => '0xffffffff',
                                           'exists' => 'true',
                                           'reset' => '0x0'
                                         },
                       'pmpaddr15' => {
                                        'exists' => 'false'
                                      },
                       'mitcnt1' => {
                                      'mask' => '0xffffffff',
                                      'number' => '0x7d5',
                                      'exists' => 'true',
                                      'reset' => '0x0'
                                    },
                       'pmpaddr6' => {
                                       'exists' => 'false'
                                     },
                       'mrac' => {
                                   'shared' => 'true',
                                   'mask' => '0xffffffff',
                                   'comment' => 'Memory region io and cache control.',
                                   'number' => '0x7c0',
                                   'exists' => 'true',
                                   'reset' => '0x0'
                                 },
                       'marchid' => {
                                      'mask' => '0x0',
                                      'reset' => '0x00000010',
                                      'exists' => 'true'
                                    },
                       'misa' => {
                                   'mask' => '0x0',
                                   'reset' => '0x40001104',
                                   'exists' => 'true'
                                 },
                       'time' => {
                                   'exists' => 'false'
                                 },
                       'meicpct' => {
                                      'mask' => '0x0',
                                      'exists' => 'true',
                                      'reset' => '0x0',
                                      'number' => '0xbca',
                                      'comment' => 'External claim id/priority capture.'
                                    },
                       'mpmc' => {
                                   'number' => '0x7c6',
                                   'reset' => '0x2',
                                   'exists' => 'true',
                                   'mask' => '0x2'
                                 },
                       'mhpmcounter5' => {
                                           'mask' => '0xffffffff',
                                           'exists' => 'true',
                                           'reset' => '0x0'
                                         },
                       'pmpaddr2' => {
                                       'exists' => 'false'
                                     },
                       'mhpmevent5' => {
                                         'exists' => 'true',
                                         'reset' => '0x0',
                                         'mask' => '0xffffffff'
                                       },
                       'mitbnd1' => {
                                      'number' => '0x7d6',
                                      'reset' => '0xffffffff',
                                      'exists' => 'true',
                                      'mask' => '0xffffffff'
                                    },
                       'mhpmevent4' => {
                                         'mask' => '0xffffffff',
                                         'exists' => 'true',
                                         'reset' => '0x0'
                                       },
                       'mhpmcounter3' => {
                                           'mask' => '0xffffffff',
                                           'reset' => '0x0',
                                           'exists' => 'true'
                                         },
                       'instret' => {
                                      'exists' => 'false'
                                    },
                       'cycle' => {
                                    'exists' => 'false'
                                  },
                       'mhpmcounter6' => {
                                           'mask' => '0xffffffff',
                                           'reset' => '0x0',
                                           'exists' => 'true'
                                         },
                       'dicawics' => {
                                       'debug' => 'true',
                                       'mask' => '0x0130fffc',
                                       'comment' => 'Cache diagnostics.',
                                       'number' => '0x7c8',
                                       'exists' => 'true',
                                       'reset' => '0x0'
                                     },
                       'mcgc' => {
                                   'reset' => '0x200',
                                   'exists' => 'true',
                                   'number' => '0x7f8',
                                   'mask' => '0x000003ff',
                                   'poke_mask' => '0x000003ff'
                                 },
                       'pmpcfg1' => {
                                      'exists' => 'false'
                                    },
                       'mhpmevent6' => {
                                         'mask' => '0xffffffff',
                                         'exists' => 'true',
                                         'reset' => '0x0'
                                       },
                       'dcsr' => {
                                   'poke_mask' => '0x00008dcc',
                                   'mask' => '0x00008c04',
                                   'debug' => 'true',
                                   'reset' => '0x40000003',
                                   'exists' => 'true'
                                 },
                       'pmpaddr10' => {
                                        'exists' => 'false'
                                      },
                       'mhartid' => {
                                      'reset' => '0x0',
                                      'exists' => 'true',
                                      'mask' => '0x0',
                                      'poke_mask' => '0xfffffff0'
                                    },
                       'mitctl1' => {
                                      'mask' => '0x0000000f',
                                      'number' => '0x7d7',
                                      'exists' => 'true',
                                      'reset' => '0x1'
                                    },
                       'mcpc' => {
                                   'reset' => '0x0',
                                   'exists' => 'true',
                                   'number' => '0x7c2',
                                   'comment' => 'Core pause',
                                   'mask' => '0x0'
                                 },
                       'mcountinhibit' => {
                                            'exists' => 'true',
                                            'reset' => '0x0',
                                            'commnet' => 'Performance counter inhibit. One bit per counter.',
                                            'poke_mask' => '0x7d',
                                            'mask' => '0x7d'
                                          },
                       'dicad0' => {
                                     'debug' => 'true',
                                     'mask' => '0xffffffff',
                                     'comment' => 'Cache diagnostics.',
                                     'exists' => 'true',
                                     'reset' => '0x0',
                                     'number' => '0x7c9'
                                   },
                       'pmpaddr7' => {
                                       'exists' => 'false'
                                     },
                       'mfdht' => {
                                    'shared' => 'true',
                                    'mask' => '0x0000003f',
                                    'comment' => 'Force Debug Halt Threshold',
                                    'number' => '0x7ce',
                                    'reset' => '0x0',
                                    'exists' => 'true'
                                  },
                       'pmpaddr1' => {
                                       'exists' => 'false'
                                     },
                       'mdccmect' => {
                                       'mask' => '0xffffffff',
                                       'number' => '0x7f2',
                                       'reset' => '0x0',
                                       'exists' => 'true'
                                     },
                       'pmpaddr3' => {
                                       'exists' => 'false'
                                     },
                       'mscause' => {
                                      'exists' => 'true',
                                      'reset' => '0x0',
                                      'number' => '0x7ff',
                                      'mask' => '0x0000000f'
                                    },
                       'pmpaddr5' => {
                                       'exists' => 'false'
                                     },
                       'mstatus' => {
                                      'reset' => '0x1800',
                                      'exists' => 'true',
                                      'mask' => '0x88'
                                    },
                       'pmpcfg0' => {
                                      'exists' => 'false'
                                    },
                       'mitctl0' => {
                                      'number' => '0x7d4',
                                      'reset' => '0x1',
                                      'exists' => 'true',
                                      'mask' => '0x00000007'
                                    },
                       'pmpaddr13' => {
                                        'exists' => 'false'
                                      },
                       'pmpaddr11' => {
                                        'exists' => 'false'
                                      },
                       'mhpmcounter3h' => {
                                            'mask' => '0xffffffff',
                                            'reset' => '0x0',
                                            'exists' => 'true'
                                          },
                       'mhpmevent3' => {
                                         'reset' => '0x0',
                                         'exists' => 'true',
                                         'mask' => '0xffffffff'
                                       },
                       'pmpaddr14' => {
                                        'exists' => 'false'
                                      },
                       'dmst' => {
                                   'mask' => '0x0',
                                   'debug' => 'true',
                                   'reset' => '0x0',
                                   'exists' => 'true',
                                   'number' => '0x7c4',
                                   'comment' => 'Memory synch trigger: Flush caches in debug mode.'
                                 },
                       'mvendorid' => {
                                        'mask' => '0x0',
                                        'reset' => '0x45',
                                        'exists' => 'true'
                                      },
                       'mimpid' => {
                                     'reset' => '0x4',
                                     'exists' => 'true',
                                     'mask' => '0x0'
                                   },
                       'mhpmcounter6h' => {
                                            'mask' => '0xffffffff',
                                            'reset' => '0x0',
                                            'exists' => 'true'
                                          }
                     },
            'numiregs' => '32',
            'nmi_vec' => '0x11110000',
            'memmap' => {
                          'unused_region2' => '0x60000000',
                          'unused_region8' => '0x00000000',
                          'unused_region0' => '0x90000000',
                          'consoleio' => '0xd0580000',
                          'unused_region6' => '0x20000000',
                          'unused_region4' => '0x40000000',
                          'external_data' => '0xc0580000',
                          'debug_sb_mem' => '0xa0580000',
                          'unused_region1' => '0x70000000',
                          'external_data_1' => '0xb0000000',
                          'unused_region3' => '0x50000000',
                          'unused_region7' => '0x10000000',
                          'serialio' => '0xd0580000',
                          'unused_region5' => '0x30000000'
                        },
            'triggers' => [
                            {
                              'poke_mask' => [
                                               '0x081818c7',
                                               '0xffffffff',
                                               '0x00000000'
                                             ],
                              'mask' => [
                                          '0x081818c7',
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
                              'reset' => [
                                           '0x23e00000',
                                           '0x00000000',
                                           '0x00000000'
                                         ],
                              'mask' => [
                                          '0x081810c7',
                                          '0xffffffff',
                                          '0x00000000'
                                        ],
                              'poke_mask' => [
                                               '0x081810c7',
                                               '0xffffffff',
                                               '0x00000000'
                                             ]
                            },
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
                              'reset' => [
                                           '0x23e00000',
                                           '0x00000000',
                                           '0x00000000'
                                         ],
                              'poke_mask' => [
                                               '0x081810c7',
                                               '0xffffffff',
                                               '0x00000000'
                                             ],
                              'mask' => [
                                          '0x081810c7',
                                          '0xffffffff',
                                          '0x00000000'
                                        ]
                            }
                          ],
            'tec_rv_icg' => 'clockhdr',
            'icache' => {
                          'icache_num_ways' => 2,
                          'icache_num_lines' => 256,
                          'icache_tag_num_bypass' => '2',
                          'icache_tag_depth' => 128,
                          'icache_data_index_lo' => 4,
                          'icache_fdata_width' => 71,
                          'icache_status_bits' => 1,
                          'icache_waypack' => '1',
                          'icache_banks_way' => 2,
                          'icache_num_lines_way' => '128',
                          'icache_beat_addr_hi' => 5,
                          'icache_2banks' => '1',
                          'icache_num_bypass' => '2',
                          'icache_ecc' => '1',
                          'icache_bank_width' => 8,
                          'icache_ln_sz' => 64,
                          'icache_num_lines_bank' => '64',
                          'icache_data_width' => 64,
                          'icache_tag_index_lo' => '6',
                          'icache_bypass_enable' => '1',
                          'icache_bank_hi' => 3,
                          'icache_data_cell' => 'ram_512x71',
                          'icache_num_beats' => 8,
                          'icache_num_bypass_width' => 2,
                          'icache_tag_num_bypass_width' => 2,
                          'icache_size' => 16,
                          'icache_bank_lo' => 3,
                          'icache_tag_cell' => 'ram_128x25',
                          'icache_index_hi' => 12,
                          'icache_tag_lo' => 13,
                          'icache_tag_bypass_enable' => '1',
                          'icache_beat_bits' => 3,
                          'icache_data_depth' => '512',
                          'icache_bank_bits' => 1,
                          'icache_scnd_last' => 6
                        },
            'num_mmode_perf_regs' => '4',
            'bus' => {
                       'ifu_bus_tag' => '3',
                       'dma_bus_id' => '1',
                       'lsu_bus_id' => '1',
                       'lsu_bus_prty' => '2',
                       'dma_bus_prty' => '2',
                       'ifu_bus_id' => '1',
                       'sb_bus_id' => '1',
                       'sb_bus_tag' => '1',
                       'lsu_bus_tag' => 3,
                       'dma_bus_tag' => '1',
                       'bus_prty_default' => '3',
                       'sb_bus_prty' => '2',
                       'ifu_bus_prty' => '2'
                     },
            'dccm' => {
                        'dccm_bits' => 14,
                        'dccm_num_banks' => '2',
                        'dccm_region' => '0xf',
                        'dccm_reserved' => '0x1400',
                        'dccm_data_cell' => 'ram_2048x39',
                        'dccm_byte_width' => '4',
                        'dccm_size' => 16,
                        'dccm_size_16' => '',
                        'dccm_bank_bits' => 1,
                        'dccm_data_width' => 32,
                        'dccm_sadr' => '0xf0040000',
                        'dccm_index_bits' => 11,
                        'dccm_ecc_width' => 7,
                        'lsu_sb_bits' => 14,
                        'dccm_num_banks_2' => '',
                        'dccm_eadr' => '0xf0043fff',
                        'dccm_rows' => '2048',
                        'dccm_width_bits' => 2,
                        'dccm_offset' => '0x40000',
                        'dccm_fdata_width' => 39
                      },
            'target' => 'default',
            'bht' => {
                       'bht_array_depth' => 64,
                       'bht_size' => 128,
                       'bht_addr_lo' => '2',
                       'bht_addr_hi' => 7,
                       'bht_hash_string' => '{ghr[5:4], hashin[5:2]^ghr[4-1:0]} // cf1',
                       'bht_ghr_size' => 6,
                       'bht_ghr_hash_1' => 1,
                       'bht_ghr_range' => '5:0'
                     },
            'reset_vec' => '0x80000000',
            'btb' => {
                       'btb_enable' => '1',
                       'btb_toffset_size' => '12',
                       'btb_index2_lo' => 6,
                       'btb_index2_hi' => 9,
                       'btb_fold2_index_hash' => 0,
                       'btb_array_depth' => 16,
                       'btb_index3_hi' => 13,
                       'btb_index3_lo' => 10,
                       'btb_btag_fold' => 1,
                       'btb_addr_hi' => 5,
                       'btb_addr_lo' => '2',
                       'btb_btag_size' => 9,
                       'btb_index1_lo' => '2',
                       'btb_size' => 32,
                       'btb_index1_hi' => 5
                     },
            'iccm' => {
                        'iccm_index_bits' => 12,
                        'iccm_sadr' => '0xee000000',
                        'iccm_bank_index_lo' => 4,
                        'iccm_offset' => '0xe000000',
                        'iccm_rows' => '4096',
                        'iccm_eadr' => '0xee00ffff',
                        'iccm_bank_hi' => 3,
                        'iccm_size_64' => '',
                        'iccm_num_banks_4' => '',
                        'iccm_reserved' => '0x1000',
                        'iccm_data_cell' => 'ram_4096x39',
                        'iccm_num_banks' => '4',
                        'iccm_bits' => 16,
                        'iccm_region' => '0xe',
                        'iccm_bank_bits' => 2,
                        'iccm_size' => 64
                      }
          );
1;
