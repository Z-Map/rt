from datetime import datetime

G_c_header_format = """/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   {0!s:<42.42s}         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {2:<40.40s}   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: {3!s:19.19s} by {1:<12.12s}      #+#    #+#             */
/*   Updated: {4!s:19.19s} by {1:<12.12s}     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

"""

def gen_42header(filename, student, mail, cdate):
	fby = student + " <" + mail + ">"
	dat1 = cdate.strftime("%Y/%m/%d %I:%M:%S")
	dat2 = datetime.now().strftime("%Y/%m/%d %I:%M:%S")
	return G_c_header_format.format(filename, student, fby, dat1, dat2)
