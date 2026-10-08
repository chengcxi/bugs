;\set\interaction_entity\tank\arm_tank-specifics_ext.inc
;rewrite by Max Drechsler
;22.08.2026
;DSL Gem Engine 2 - macros
;v.1.0

;/===================== SCRIPT CANNON + TANK BOT TEXMOD BEGIN

{"tank"
	{on spawn
		{if tagged "_ai_defender"
			{delay 0.1
				{if terrain_fx "ice"
					{tex_mod "winter"}
				else terrain_fx "snow"
					{tex_mod "winter"}
				else
					; do nothing — оставляем стандартную текстуру
				}
			}
		}
		{if tagged "bot_veh"
			{delay 0.1
				{if terrain_fx "ice"
					{tex_mod "winter"}
				else terrain_fx "snow"
					{tex_mod "winter"}
				else
					; do nothing — оставляем стандартную текстуру
				}
			}
		}
		{if tagged "cmp_mg"
			{delay 0.1
				{if terrain_fx "ice"
					{tex_mod "winter"}
				else terrain_fx "snow"
					{tex_mod "winter"}
				else
					; do nothing — оставляем стандартную текстуру
				}
			}
		}	
		{if tagged "no_scavenge"
			{delay 0.1
				{if terrain_fx "ice"
					{tex_mod "winter"}
				else terrain_fx "snow"
					{tex_mod "winter"}
				else
					; do nothing — оставляем стандартную текстуру
				}
			}
		}		
	}
}

{"tank detect_artillery rocket"
    {on spawn
        {delay 1
            {tags add "short_range"}
        }
    }
}

; ===== Artillery ===== 
    {"tank artillery_minimap_medium_2" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"tank detect_artillery" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"tank artillery_minimap_medium" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"tank artillery_minimap_heavy" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"spg artillery_minimap_medium" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"spg detect_artillery" 
        {on spawn
            {delay 0.2
                {tags add "artillery"}
            }
        }
    }

    {"nebelwerfer" 
        {on spawn
            {delay 0.2
                {call "tag_rocket_artillery"}
            }
        }
    }

    {"katusha"
        {on spawn
            {delay 0.2
                {call "tag_rocket_artillery"}
            }
        }
    }

{"mine_exploder"
    {on spawn
        {delay 0.2
            {if not user_control
                {call "set_ignore_spawn_logic"}
                {tags add "_lua_mi"}
            }
        }
    }

    {on "search_for_minses"
        {if operatable
            {if not user_control
                {tags add "clearing_mines"}
                {tags remove "mine_clearer_selected"}
                {delay 60
                    {tags remove "clearing_mines"}
                }
            }
        }
    }

    {on "remove_mine_sweeper"
        {if operatable
            {if not user_control
                {tags add "mine_clear_not_needed"}
                {hide 10}
            }
        }
    }
}

; ===== Radio Vehicle Tagging ========================================
	{"sdkfz250a_3" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

	{"ba20_command" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

	{"ba20_command_fin" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

    {"armored_command" 				; disabled
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}
    

	{"m3a1_halftrack_radio" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}
	
	{"m3a1_commander" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}
	
	

	{"blitz3_6_radio" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

   {"t34_kwk37" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

   {"pz6p_Panzerbefehiswagen" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}

	{"daf_39_com" 
		{on spawn
			{delay 0.2
				{if work "body"
					("tag_veh" args "radio_car")
				}
			}
		}
	}
	
; ===== Radio Vehicle Tagging End ====================================

;/*=========== Specific Vehicle Logic Begin ===========*/    
	{"marder3m tank"
	    ("pz38_sound")
	    {on "spawn_shell_delay" overload
	        ("shell_eject_delay" args 0.15 0.25)
	    }
	}

	{"sdkfz303b"
        {on spawn
            {delay 10
                {able "select" 1}
                {drop_orders}
            }
        }
    }

	{"sdkfz251c"
	    {on pierce
	        {if not user_control
	           {if not linked
	               {delay 1
	                    {crew_emit}
	                }
	            }
	        }
	    }
	}

	{"sdkfz221" 
		{on "hull_down"
			{delay 8
		   	    {spawn "sandbag_heap_straight" offset 110 40 0}
		   	    {spawn "sandbag_heap_straight" offset 110 -40 0}
		   	    {delay 2
					{spawn "sandbag_heap_pile" offset 100 -100 0}
					{delay 2
				   	    {spawn "sandbag_heap_straight_90" offset 40 -110 0}
				   	    {spawn "sandbag_heap_straight_90" offset -40 -110 0}
				   	    {delay 2
							{spawn "sandbag_heap_pile" offset -100 -100 0}
							{delay 2
								{spawn "sandbag_heap_straight" offset -110 40 0}
		   	    				{spawn "sandbag_heap_straight" offset -110 -40 0}
		   	    				{delay 2
				   	    			{spawn "sandbag_heap_straight_90" offset 40 110 0}
				   	    			{spawn "sandbag_heap_straight_90" offset -40 110 0}
				   	    			{delay 2
										{spawn "sandbag_heap_pile" offset 100 100 0}
									}
				   	    		}
							}
						}
				   	}
				}
		   	}
		}
	}

	{"sdkfz222a" 
		{on "hull_down"
			{delay 8
		   	    {spawn "sandbag_heap_straight" offset 110 40 0}
		   	    {spawn "sandbag_heap_straight" offset 110 -40 0}
		   	    {delay 2
					{spawn "sandbag_heap_pile" offset 100 -100 0}
					{delay 2
				   	    {spawn "sandbag_heap_straight_90" offset 40 -110 0}
				   	    {spawn "sandbag_heap_straight_90" offset -40 -110 0}
				   	    {delay 2
							{spawn "sandbag_heap_pile" offset -100 -100 0}
							{delay 2
								{spawn "sandbag_heap_straight" offset -110 40 0}
		   	    				{spawn "sandbag_heap_straight" offset -110 -40 0}
		   	    				{delay 2
				   	    			{spawn "sandbag_heap_straight_90" offset 40 110 0}
				   	    			{spawn "sandbag_heap_straight_90" offset -40 110 0}
				   	    			{delay 2
										{spawn "sandbag_heap_pile" offset 100 100 0}
									}
				   	    		}
							}
						}
				   	}
				}
		   	}
		}
	}

	{"t27" 
		{on "hull_down"
			{delay 8
		   	    {spawn "sandbag_heap_straight" offset 110 40 0}
		   	    {spawn "sandbag_heap_straight" offset 110 -40 0}
		   	    {delay 2
					{spawn "sandbag_heap_pile" offset 100 -100 0}
					{delay 2
				   	    {spawn "sandbag_heap_straight_90" offset 40 -110 0}
				   	    {spawn "sandbag_heap_straight_90" offset -40 -110 0}
				   	    {delay 2
							{spawn "sandbag_heap_pile" offset -100 -100 0}
							{delay 2
								{spawn "sandbag_heap_straight" offset -110 40 0}
		   	    				{spawn "sandbag_heap_straight" offset -110 -40 0}
		   	    				{delay 2
				   	    			{spawn "sandbag_heap_straight_90" offset 40 110 0}
				   	    			{spawn "sandbag_heap_straight_90" offset -40 110 0}
				   	    			{delay 2
										{spawn "sandbag_heap_pile" offset 100 100 0}
									}
				   	    		}
							}
						}
				   	}
				}
		   	}
		}
	}

	{"panzerb2" 
		{on "hull_down"
			{delay 8
		   	    {spawn "sandbag_heap_straight" offset 110 40 0}
		   	    {spawn "sandbag_heap_straight" offset 110 -40 0}
		   	    {delay 2
					{spawn "sandbag_heap_pile" offset 100 -100 0}
					{delay 2
				   	    {spawn "sandbag_heap_straight_90" offset 40 -110 0}
				   	    {spawn "sandbag_heap_straight_90" offset -40 -110 0}
				   	    {delay 2
							{spawn "sandbag_heap_pile" offset -100 -100 0}
							{delay 2
								{spawn "sandbag_heap_straight" offset -110 40 0}
		   	    				{spawn "sandbag_heap_straight" offset -110 -40 0}
		   	    				{delay 2
			   	    			{spawn "sandbag_heap_straight_90" offset 40 110 0}
			   	    			{spawn "sandbag_heap_straight_90" offset -40 110 0}
			   	    			{delay 2
									{spawn "sandbag_heap_pile" offset 100 100 0}
								}
				   	    		}
							}
						}
				   	}
				}
		   	}
		}
	}
;/*=========== Specific Vehicle Logic End ===========*/    

;/*=========== minesweeper Vehicles Begin ===========*/

	{"t34m tank"
		("t34_sound")
		{on "add_weapon_sound" overload
			("DT")
		}
	}
	
	{"m4a3m tank"
		("m4a2_sherman_sound")
	}
	
	{"pz3m tank"
		("pz3_sound")
		{on "add_weapon_sound" overload
			("MG34")
		}
	}

;/*=========== minesweeper Vehicles End ===========*/

;============================TDs and SPGs ============================
	; grille_k and bison
	{"spg light -turret muzzle_150mm_155mm"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 25
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	; sig33 and sturmpanzer 4
	{"spg medium -turret muzzle_122mm_128mm vision_lev05"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 25
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	{"jagdtiger"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 16
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	{"sturmtiger"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 100
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	{"su122"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 15
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	{"isu122s"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 15
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

	; su152 and isu152
	{"td heavy -turret muzzle_150mm_155mm_sides"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 30
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}


	{"kv2_40"
	    {on fire "gun"
	        {if not user_control
	            {if tagged "bot_tank"
	                {call "engine_off"}
	                {delay 25
	                    {if operatable
	                        {if not user_control
	                            {if tagged "bot_tank"  
	                                {if not "engine_on"
	                                    {call "engine_on"}
	                                }
	                            }
	                        }
	                    }  
	                }
	            }
	        }
	    }
	}

;//	{"hetzer" 
;//	{on "hull_down"
;//		{delay 8
;//	   	    {spawn "sandbag_heap_straight" offset 110 40 0}
;//	   	    {spawn "sandbag_heap_straight" offset 110 -40 0}
;//	   	    {delay 2
;//				{spawn "sandbag_heap_pile" offset 100 -100 0}
;//				{delay 2
;//			   	    {spawn "sandbag_heap_straight_90" offset 40 -110 0}
;//			   	    {spawn "sandbag_heap_straight_90" offset -40 -110 0}
;//			   	    {delay 2
;//						{spawn "sandbag_heap_pile" offset -100 -100 0}
;//						{delay 2
;//							{spawn "sandbag_heap_straight" offset -110 40 0}
;//	   	    				{spawn "sandbag_heap_straight" offset -110 -40 0}
;//	   	    				{delay 2
;//			   	    			{spawn "sandbag_heap_straight_90" offset 40 110 0}
;//			   	    			{spawn "sandbag_heap_straight_90" offset -40 110 0}
;//			   	    			{delay 2
;//									{spawn "sandbag_heap_pile" offset 100 100 0}
;//								}
;//			   	    		}
;//						}
;//					}
;//			   	}
;//			}
;//	   	}
;//	}
;//	}
; ===== Artillery ===== 
	{"pz38h_w40" 
		{on spawn
			{delay 1
				{call "tag_rocket_artillery"}
			}
		}
	}

	{"150mm_sig33" 
		{on spawn
			{delay 1
				{tags remove "artillery"}
				{tags remove "heavy_artillery"}
			}
		}
	}


	{"m4a3_calliope" 
		{on spawn
			{delay 1
				{call "tag_rocket_artillery"}
			}
		}
	}

	{"panzerwerfer42" 
		{on spawn
			{delay 1
				{call "tag_rocket_artillery"}
				{tags add "long_range_rocket"}
			}
		}
	}
	{"m7b1_hmc" 
		{on spawn
			{delay 1
				{tags add "artillery"}
			}
		}
	}

	{"m7_hmc" 
		{on spawn
			{delay 1
				{tags add "artillery"}
			}
		}
	}
	{"m12_gmc" 
		{on spawn
			{delay 1
				{tags add "long_range"}
			}
		}
	}

	{"grille_k" 
		{on spawn
			{delay 1
				{tags add "short_range"}
			}
		}
	}
;=====================================================================
; ===== Runnging to ReSupply Vehicles ===== 
	{"flag_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"inf_crate_ger"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"inf_crate_rus"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}	
	
	{"inf_crate_fin"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}	

	{"inf_crate_usa"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}	
	
	{"inf_crate_eng"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}	

	{"inf_crate_ger_stand"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	{"inf_crate_rus_stand"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}	
	
	{"inf_crate_fin_stand"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}	

	{"inf_crate_usa_stand"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}	
	
	{"inf_crate_eng_stand"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"infantry_cart_if8"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	
	{"sdkfz6_supply"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}	

	{"sdkfz251c_tarp"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	{"bt2_supply_rus"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	{"t34_44supply"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}



	{"ford_3ton_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"ford_v3000_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	{"blitz3_6_art_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"opel_maultier"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"sdkfz6_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"ammo_trailer"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}

	{"gaz_aaa_supply"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"ap_2"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"c_supply"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"cckw_art_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"cckw_redball"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"bedford_oyd_art_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"bedford_qld_art_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}


	; ====== MACE ======
	{"gmc_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}
	{"stud_ammo"
		{on spawn
			{delay 0.2
				{call "tag_supplies"}
			}
		}
	}