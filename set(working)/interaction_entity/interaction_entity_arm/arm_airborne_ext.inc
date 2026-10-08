{"po2_fin"
	("po2_sound")
	{on "wing_tear" overload
		{if volume "wingl1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireL_ail")
				{tear "piece_big_airborne_wing" bone "wingl2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingl1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		else volume "wingr1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireR_ail")
				{tear "piece_big_airborne_wing" bone "wingr2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingr1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		}
	}
	{on "tear_part"
		{if volume "elevator1"
			("cut_part_delete" args "wireL_elev")
		}
		{if volume "elevator2"
			("cut_part_delete" args "wireR_elev")
		}
		{if volume "rudder1"
			("cut_part_delete" args "wire_rud")
		}

		;//Left Wings
		{if volume "aileron1"
			("cut_part_delete" args "wireL_top")
			("cut_part_delete" args "wireL_ail")
		}
		{if volume "aileron3"
			("cut_part_delete" args "wireL_bottom")
			("cut_part_delete" args "wireL_ail")
		}

		;//Right Wings
		{if volume "aileron2"
			("cut_part_delete" args "wireR_top")
			("cut_part_delete" args "wireR_ail")
		}
		{if volume "aileron4"
			("cut_part_delete" args "wireR_bottom")
			("cut_part_delete" args "wireR_ail")
		}
	}
}

{"po2_fin_ai"
	("po2_sound")
	{on "wing_tear" overload
		{if volume "wingl1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireL_ail")
				{tear "piece_big_airborne_wing" bone "wingl2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingl1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		else volume "wingr1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireR_ail")
				{tear "piece_big_airborne_wing" bone "wingr2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingr1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		}
	}
	{on "tear_part"
		{if volume "elevator1"
			("cut_part_delete" args "wireL_elev")
		}
		{if volume "elevator2"
			("cut_part_delete" args "wireR_elev")
		}
		{if volume "rudder1"
			("cut_part_delete" args "wire_rud")
		}

		;//Left Wings
		{if volume "aileron1"
			("cut_part_delete" args "wireL_top")
			("cut_part_delete" args "wireL_ail")
		}
		{if volume "aileron3"
			("cut_part_delete" args "wireL_bottom")
			("cut_part_delete" args "wireL_ail")
		}

		;//Right Wings
		{if volume "aileron2"
			("cut_part_delete" args "wireR_top")
			("cut_part_delete" args "wireR_ail")
		}
		{if volume "aileron4"
			("cut_part_delete" args "wireR_bottom")
			("cut_part_delete" args "wireR_ail")
		}
	}
}